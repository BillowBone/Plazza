/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** FantasiaPizza.cpp
*/

#include "IngredientGenerator.hpp"
#include "FantasiaPizza.hpp"

namespace plazza {
    namespace food {
        FantasiaPizza::FantasiaPizza(PizzaSize size, int idCommand)
        {
            this->_type = Fantasia;
            this->_size = size;
            this->_idCommand = idCommand;
            this->_bakingTime = 4;
            this->_ingredients.reserve(5);
            this->_ingredients.push_back(IngredientGenerator::generateFood(Doe));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Tomato));
            this->_ingredients.push_back(IngredientGenerator::generateFood(Eggplant));
            this->_ingredients.push_back(IngredientGenerator::generateFood(GoatCheese));
            this->_ingredients.push_back(IngredientGenerator::generateFood(ChiefLove));
        }

        FantasiaPizza::~FantasiaPizza()
        {
        }
    }
}