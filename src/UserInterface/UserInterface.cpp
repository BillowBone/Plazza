/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** UserInterface.cpp
*/

#include "UserInterface.hpp"

namespace plazza {
    UserInterface::UserInterface(float coeffBaking, int nbCooks, int regeneration)
    {
        std::unique_ptr<Reception> reception(new Reception(coeffBaking, nbCooks, regeneration));

        this->reception = std::move(reception);
        this->interactiveShell();
    }

    UserInterface::~UserInterface()
    {
    }

    int UserInterface::getCommand()
    {
        fd_set readSet;
        struct timeval tv {0, 100};
        char buffer[1024];
        int ret = 0;

        FD_ZERO(&readSet);
        FD_SET(STDIN_FILENO, &readSet);
        ret = select(STDIN_FILENO + 1, &readSet, NULL, NULL, &tv);
        if (ret == -1) {
            std::perror("select()");
            std::exit(84);
        } else if (ret) {
            if (FD_ISSET(STDIN_FILENO, &readSet) == 1) {
                std::cin.getline(buffer, sizeof(buffer));
                this->command = buffer;
                return (1);
            }
        } else {
            this->reception->manageFinishedPizzas();
            return (0);
        }
    }

    void UserInterface::interactiveShell()
    {
        int ret = 0;
        std::shared_ptr<Command> cmd;

        while (1) {
            ret = this->getCommand();
            if (ret && this->command.compare("status") != 0) {
                cmd = Parser::parseCommand(this->command, this->reception->getNewCommandId());
                if (cmd == nullptr) {
                    this->reception->eraseNewCommandId();
                    std::cout << "Wrong syntax, command not taken into account!" << std::endl;
                    continue;
                } else {
                    std::cout << std::endl << "Your order has the ID " << cmd->getId() << ", you will be noticed when it's done!" << std::endl;
                    this->reception->setNewCommand(cmd);
                }
            } else if (ret && this->command.compare("status") == 0) {
                this->reception->displayStatus();
            }
        }
    }
}