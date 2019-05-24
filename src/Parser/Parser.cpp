/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Parser.cpp
*/

#include <cstdlib>
#include "UserInterface.hpp"
#include "Parser.hpp"

namespace plazza {
    Parser::Parser(int argc, char *argv[])
    {
        bool dot = false;

        if (argc != 4)
            std::exit(84);
        for (int i = 0; argv[1][i] != 0; i++) {
            if (argv[1][i] == 46 && !dot) {
                dot = true;
                continue;
            } else if (argv[1][i] == 46 && dot) {
                std::exit(84);
            }
            if (argv[1][i] < 48 || argv[1][i] > 57)
                std::exit(84);
        }
        for (int j = 0; argv[2][j] != 0; j++) {
            if (argv[2][j] < 48 || argv[2][j] > 57)
                std::exit(84);
        }
        for (int k = 0; argv[3][k] != 0; k++) {
            if (argv[3][k] < 48 || argv[3][k] > 57)
                std::exit(84);
        }
        UserInterface ui(std::atof(argv[1]), std::atoi(argv[2]), std::atoi(argv[3]));
    }

    Parser::~Parser()
    {
    }

    std::shared_ptr<Command> Parser::parseCommand(const std::string &cmd, int id)
    {
        std::shared_ptr<Command> command(new Command(id, cmd));
        std::stringstream buffer(cmd);
        std::string line;
        food::PizzaType type;
        food::PizzaSize size;
        int quantity = 0;

        if (!cmd.length())
            return (nullptr);
        while (std::getline(buffer, line, ';')) {
            if (line == "")
                break;
            if (line[0] == 32)
                line = line.substr(1, line.length());
            if (!Parser::verifyCommand(line))
                return (nullptr);
            type = Parser::parseType(line);
            if (type == food::PizzaType::None)
                return (nullptr);
            size = Parser::parseSize(line);
            if (size == food::PizzaSize::Null)
                return (nullptr);
            quantity = Parser::parseQuantity(line);
            if (quantity == 0)
                return (nullptr);
            command->addPizza(type, size, quantity);
        }
        return (command);
    }

    bool Parser::verifyCommand(const std::string &cmd)
    {
        int spaces = 0;

        for (int i = 0; i < cmd.length(); i++) {
            if (cmd[i] == 32)
                spaces++;
        }
        if (spaces != 2)
            return (false);
        else
            return (true);
    }

    food::PizzaType Parser::parseType(const std::string &line)
    {
        if (line.compare(0, 9, "margarita") == 0)
            return (food::PizzaType::Margarita);
        else if (line.compare(0, 6, "regina") == 0)
            return (food::PizzaType::Regina);
        else if (line.compare(0, 8, "fantasia") == 0)
            return (food::PizzaType::Fantasia);
        else if (line.compare(0, 9, "americana") == 0)
            return (food::PizzaType::Americana);
        else
            return (food::PizzaType::None);
    }

    food::PizzaSize Parser::parseSize(const std::string &line)
    {
        int begin = 0;
        int end = 0;
        std::string sub;

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == 32 && begin == 0)
                begin = i + 1;
            else if (line[i] == 32 && begin != 0)
                end = i;
        }
        sub = line.substr(begin, end - begin);
        if (sub.compare("S") == 0)
            return (food::PizzaSize::S);
        else if (sub.compare("M") == 0)
            return (food::PizzaSize::M);
        else if (sub.compare("L") == 0)
            return (food::PizzaSize::L);
        else if (sub.compare("XL") == 0)
            return (food::PizzaSize::XL);
        else if (sub.compare("XXL") == 0)
            return (food::PizzaSize::XXL);
        else
            return (food::PizzaSize::Null);
    }

    int Parser::parseQuantity(const std::string &line)
    {
        int begin = 0;
        int spaces = 0;
        std::string sub;

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == 32)
                spaces++;
            if (line[i] == 32 && spaces == 2)
                begin = i + 1;
        }
        sub = line.substr(begin, line.length());
        if (sub[0] != 'x')
            return (0);
        sub = sub.substr(1, sub.length());
        for (int j = 0; j < sub.length(); j++) {
            if (sub[j] < 48 || sub[j] > 57)
                return (0);
        }
        return (std::atoi(sub.c_str()));
    }
}