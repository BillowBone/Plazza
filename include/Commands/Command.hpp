/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Command.hpp
*/

#ifndef COMMAND_HPP_
    #define COMMAND_HPP_

#include <memory>
#include <vector>
#include <utility>
#include "IPizza.hpp"

namespace plazza {
    class Command {
        public:
            Command(int id, const std::string &order);
            ~Command();
            bool isDone() const;
            void addPizza(food::PizzaType type, food::PizzaSize size, int quantity);
            void pack(food::PizzaType type, food::PizzaSize);
            int getId() const;
            int getSize() const;
            std::string unpack(int i) const;
            std::string getOrderString() const;
        private:
            int id;
            std::vector<std::unique_ptr<food::IPizza>> pizzas;
            std::string order;
    };
}

#endif /* !COMMAND_HPP_ */