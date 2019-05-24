/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

#include <istream>
#include <sstream>
#include <memory>
#include "IPizza.hpp"
#include "Command.hpp"

namespace plazza {
    class Parser {
        public:
            Parser(int argc, char *argv[]);
            ~Parser();
            static std::shared_ptr<Command> parseCommand(const std::string &cmd, int id);
        private:
            static bool verifyCommand(const std::string &cmd);
            static food::PizzaType parseType(const std::string &line);
            static food::PizzaSize parseSize(const std::string &line);
            static int parseQuantity(const std::string &line);
    };
}

#endif /* !PARSER_HPP_ */