/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** MargaritaPizza.cpp
*/

#include "IngredientGenerator.hpp"
#include "MargaritaPizza.hpp"

namespace plazza {
    namespace food {
        MargaritaPizza::MargaritaPizza(PizzaSize size, int idCommand)
        {
            this->_type = Margarita;
            this->_size = size;
            this->_idCommand = idCommand;
            this->_bakingTime = 1;
            this->_ingredients.reserve(3);
            this->_ingredients.push_back(IngredientGenerator::generateFood(Doe));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Tomato));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Gruyere));
        }

        MargaritaPizza::~MargaritaPizza()
        {
        }
    }
}