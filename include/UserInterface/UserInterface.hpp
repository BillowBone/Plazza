/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** UserInterface.hpp
*/

#ifndef USERINTERFACE_HPP_
    #define USERINTERFACE_HPP_

#include <sys/select.h>
#include <memory>
#include <iostream>
#include "Parser.hpp"
#include "Reception.hpp"
#include "Command.hpp"

namespace plazza {
    class UserInterface {
        public:
            UserInterface(float coeffBaking, int nbCooks, int regeneration);
            ~UserInterface();
            int getCommand();
            void interactiveShell();
        private:
            std::string command;
            std::unique_ptr<Reception> reception;
    };
}

#endif /* !USERINTERFACE_HPP_ */