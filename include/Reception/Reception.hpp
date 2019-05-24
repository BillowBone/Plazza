/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Reception.hpp
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <memory>
#include <chrono>
#include "Kitchen.hpp"
#include "Messenger.hpp"
#include "Command.hpp"
#include "Logger.hpp"

namespace plazza {
    typedef struct kitchen_s {
        int id;
        int occupancy;
        std::time_t noWork;
        int exited;
        bool exitMessage;
    } kitchen_t;

    class Reception {
        public:
            Reception(float coeffBaking, int nbCooks, int regeneration);
            ~Reception();
            int getNewCommandId();
            void eraseNewCommandId();
            void setNewCommand(std::shared_ptr<Command> command);
            void manageFinishedPizzas();
            void displayStatus() const;
        private:
            int kitchenCreated;
            float coeffBaking;
            int nbCooks;
            int regeneration;
            int nbCommands;
            std::unique_ptr<ipc::Messenger> messenger;
            std::vector<kitchen_t> kitchens;
            std::vector<std::shared_ptr<Command>> commands;
            void createKitchen();
            int getLessBusyKitchen();
            void manageFinishedCommands(int indiceCommand);
            void manageFinishedKitchen();
            int getIndiceCommand(int idCommand);
            std::pair<food::PizzaType, food::PizzaSize> interpretMessage(const std::string &cmd);
    };
}

#endif /* !RECEPTION_HPP_ */