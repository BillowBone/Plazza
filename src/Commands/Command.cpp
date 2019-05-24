/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Command.cpp
*/

#include <iostream>
#include "Command.hpp"
#include "PizzaGenerator.hpp"

namespace plazza {
    Command::Command(int id, const std::string &order)
    {
        this->id = id;
        this->order = order;
    }

    Command::~Command()
    {
    }

    bool Command::isDone() const
    {
        if (this->pizzas.size() == 0)
            return (true);
        else
            return (false);
    }

    void Command::addPizza(food::PizzaType type, food::PizzaSize size, int quantity)
    {
        for (int i = 0; i < quantity; i++) {
            this->pizzas.push_back(food::PizzaGenerator::generatePizza(type, size, this->id));
        }
    }

    void Command::pack(food::PizzaType type, food::PizzaSize size)
    {
        for (int i = 0; i < this->pizzas.size(); i++) {
            if (this->pizzas[i]->getType() == type && this->pizzas[i]->getSize() == size) {
                this->pizzas.erase(this->pizzas.begin() + i);
                return;
            }
        }
    }

    int Command::getId() const
    {
        return (this->id);
    }

    int Command::getSize() const
    {
        return (this->pizzas.size());
    }

    std::string Command::unpack(int i) const
    {
        std::string ret;
        std::pair<food::PizzaType, food::PizzaSize> pr {food::PizzaType::None, food::PizzaSize::Null};

        if (i >= this->pizzas.size())
            return (nullptr);
        pr.first = this->pizzas[i]->getType();
        pr.second = this->pizzas[i]->getSize();
        ret = std::to_string(pr.first) + "," + std::to_string(pr.second) + "," + std::to_string(this->id);
        return (ret);
    }

    std::string Command::getOrderString() const
    {
        return (this->order);
    }
}