/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** AmericanaPizza.cpp
*/

#include "IngredientGenerator.hpp"
#include "AmericanaPizza.hpp"

namespace plazza {
    namespace food {
        AmericanaPizza::AmericanaPizza(PizzaSize size, int idCommand)
        {
            this->_type = Americana;
            this->_size = size;
            this->_idCommand = idCommand;
            this->_bakingTime = 2;
            this->_ingredients.reserve(4);
            this->_ingredients.push_back(IngredientGenerator::generateFood(Doe));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Tomato));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Gruyere));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Steak));
        }

        AmericanaPizza::~AmericanaPizza()
        {
        }
    }
}