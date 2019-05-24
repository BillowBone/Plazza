/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Reception.cpp
*/

#include <iostream>
#include <exception>
#include <cstdlib>
#include "Reception.hpp"
#include "Exceptions.hpp"

namespace plazza {
    Reception::Reception(float coeffBaking, int nbCooks, int regeneration)
    {
        std::unique_ptr<ipc::Messenger> messenger(new ipc::Messenger());

        this->messenger = std::move(messenger);
        this->coeffBaking = coeffBaking;
        this->nbCooks = nbCooks;
        this->regeneration = regeneration;
        this->kitchenCreated = 0;
        this->nbCommands = 0;
    }

    Reception::~Reception()
    {
    }

    void Reception::setNewCommand(std::shared_ptr<Command> command)
    {
        int kitchenIndice = 0;

        this->commands.push_back(command);
        Logger::newEntry(command->getOrderString());
        for (int i = 0; i < command->getSize(); i++) {
            kitchenIndice = this->getLessBusyKitchen();
            this->kitchens[kitchenIndice].occupancy++;
            this->messenger->sendMessageToKitchen(this->kitchens[kitchenIndice].id, command->unpack(i));
        }
    }

    int Reception::getNewCommandId()
    {
        this->nbCommands++;
        return (this->nbCommands);
    }

    void Reception::eraseNewCommandId()
    {
        this->nbCommands--;
    }

    void Reception::createKitchen()
    {
        pid_t pid;

        this->kitchenCreated++;
        kitchen_t tmp {this->kitchenCreated, 0, std::time(nullptr), 0, false};
        this->kitchens.push_back(tmp);
        this->messenger->addQueue(this->kitchenCreated);
        pid = fork();
        if (pid == 0) {
            try {
                kitchen::Kitchen kitchen(this->kitchenCreated, this->nbCooks, this->regeneration, this->coeffBaking);
                std::_Exit(0);
            } catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
                std::_Exit(0);
            }
        }
    }

    int Reception::getLessBusyKitchen()
    {
        int less = this->nbCooks * 2 - 1;
        int newKitchen = 0;

        for (int i = 0; i < this->kitchens.size(); i++) {
            if (!this->kitchens[i].exitMessage && this->kitchens[i].occupancy < less)
                less = this->kitchens[i].occupancy;
        }
        for (int j = 0; j < this->kitchens.size(); j++) {
            if (this->kitchens[j].occupancy == less) {
                less = j;
                newKitchen = 1;
                break;
            }
        }
        if (newKitchen == 0) {
            this->createKitchen();
            return (this->kitchens.size() - 1);
        } else {
            return (less);
        }
    }

    void Reception::manageFinishedPizzas()
    {
        std::string buff;
        int len = 0;
        int ret = 0;
        int indiceCommand = 0;
        int toRemove = 0;
        int idCommand = 0;
        std::pair<food::PizzaType, food::PizzaSize> pizza;

        this->manageFinishedKitchen();
        for (int j = 0; j < this->kitchens.size(); j++) {
            for (int k = 0; k < this->kitchens[j].occupancy; k++) {
                ret = this->messenger->receiveMessageFromKitchen(this->kitchens[j].id, buff);
                if (ret > 0) {
                    len = buff.length() - 3;
                    buff = buff.substr(0, len);
                    pizza = this->interpretMessage(buff);
                    if (buff[3] == ',')
                        idCommand = std::atoi(buff.c_str() + 4);
                    else
                        idCommand = std::atoi(buff.c_str() + 5);
                    indiceCommand = this->getIndiceCommand(idCommand);
                    toRemove++;
                    this->commands[indiceCommand]->pack(pizza.first, pizza.second);
                    this->manageFinishedCommands(indiceCommand);
                }
                buff.clear();
            }
            if (this->kitchens[j].occupancy  - toRemove == 0 && toRemove != 0)
                this->kitchens[j].noWork = std::time(nullptr);
            this->kitchens[j].occupancy -= toRemove;
            toRemove = 0;
        }
    }

    void Reception::manageFinishedCommands(int indiceCommand)
    {
        if (this->commands[indiceCommand]->isDone()) {
            Logger::newEntry(this->commands[indiceCommand]->getOrderString() + " DONE");
            std::cout << std::endl << "The command n°" << this->commands[indiceCommand]->getId();
            std::cout << " (" << this->commands[indiceCommand]->getOrderString() << ") is now done!" << std::endl;
            this->commands.erase(this->commands.begin() + indiceCommand);
        }
    }

    void Reception::displayStatus() const
    {
        if (this->kitchens.size() == 0) {
            std::cout << std::endl << "There are currently 0 kitchen open!" << std::endl << std::endl;
        } else {
            for (int i = 0; i < this->kitchens.size(); i++) {
                std::cout << std::endl << "Kitchen " << i + 1 << ":" << std::endl;
                std::cout << "\tThis kitchen has the ID " << this->kitchens[i].id << std::endl;
                std::cout << "\tIt has an occupancy of " << this->kitchens[i].occupancy << " pizzas" << std::endl;
                std::cout << "\tThere are " << (this->kitchens[i].occupancy >= this->nbCooks ? this->nbCooks : this->kitchens[i].occupancy) << " cooks currently working in it" << std::endl;
                std::cout << "\tThere are " << (this->kitchens[i].occupancy < this->nbCooks ? this->nbCooks - this->kitchens[i].occupancy : 0) << " cooks that aren't working in it" << std::endl;
                std::cout << std::endl;
            }
        }
    }

    void Reception::manageFinishedKitchen()
    {
        std::string buff;
        int ret = 0;

        for (int i = 0; i < this->kitchens.size(); i++) {
            std::time_t time_elapsed = std::time(nullptr);
            if (time_elapsed - this->kitchens[i].noWork > 5 && this->kitchens[i].occupancy == 0 && !this->kitchens[i].exitMessage) {
                for (int j = 0; j < this->nbCooks; j++) {
                    this->messenger->sendMessageToKitchen(this->kitchens[i].id, "EXIT");
                    this->kitchens[i].exitMessage = true;
                }
            }
        }
        for (int i = 0; i < this->kitchens.size(); i++) {
            if (this->kitchens[i].occupancy == 0) {
                ret = this->messenger->receiveMessageFromKitchen(this->kitchens[i].id, buff);
                if (ret > 0 && buff.compare("EXIT OK") == 0) {
                    this->kitchens[i].exited++;
                    buff.clear();
                    continue;
                }
            }
        }
        int n = this->kitchens.size() - 1;
        if (n == -1)
            return;
        while (n >= 0) {
            if (this->kitchens[n].exited == this->nbCooks) {
                this->kitchens.erase(this->kitchens.begin() + n);
            }
            n--;
        }
    }

    int Reception::getIndiceCommand(int idCommand)
    {
        for (int i = 0; i < this->commands.size(); i++) {
            if (this->commands[i]->getId() == idCommand)
                return (i);
        }
        throw InvalidCommandException("A non-existing command was requested", "Reception");
    }

    std::pair<food::PizzaType, food::PizzaSize> Reception::interpretMessage(const std::string &cmd)
    {
        std::pair<food::PizzaType, food::PizzaSize> parsed;

        switch (cmd[0]) {
            case '1':
                parsed.first = food::PizzaType::Regina;
                break;
            case '2':
                parsed.first = food::PizzaType::Margarita;
                break;
            case '4':
                parsed.first = food::PizzaType::Americana;
                break;
            case '8':
                parsed.first = food::PizzaType::Fantasia;
                break;
        }
        switch (cmd[2]) {
            case '1':
                if (cmd[3] == ',')
                    parsed.second = food::PizzaSize::S;
                else
                    parsed.second = food::PizzaSize::XXL;
                break;
            case '2':
                parsed.second = food::PizzaSize::M;
                break;
            case '4':
                parsed.second = food::PizzaSize::L;
                break;
            case '8':
                parsed.second = food::PizzaSize::XL;
                break;
        }
        return (parsed);
    }
}