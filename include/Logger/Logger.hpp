/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Logger.hpp
*/

#ifndef LOGGER_HPP_
    #define LOGGER_HPP_

#include <iostream>

namespace plazza {
    class Logger {
        public:
            static void newEntry(const std::string &entry);
        private:
            static void displayNumTwoDigits(std::ofstream &file, int num);
    };
}

#endif /* !LOGGER_HPP_ */