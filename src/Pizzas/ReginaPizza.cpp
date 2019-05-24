/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** ReginaPizza.cpp
*/

#include "IngredientGenerator.hpp"
#include "ReginaPizza.hpp"

namespace plazza {
    namespace food {
        ReginaPizza::ReginaPizza(PizzaSize size, int idCommand)
        {
            this->_type = Regina;
            this->_size = size;
            this->_idCommand = idCommand;
            this->_bakingTime = 2;
            this->_ingredients.reserve(5);
            this->_ingredients.push_back(IngredientGenerator::generateFood(Doe));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Tomato));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Gruyere));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Ham));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Mushrooms));
        }

        ReginaPizza::~ReginaPizza()
        {
        }
    }
}