/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** AIngredient.cpp
*/

#include "AIngredient.hpp"

namespace plazza {
    namespace food {
        AIngredient::AIngredient()
        {
        }

        AIngredient::~AIngredient()
        {
        }

        IngredientType AIngredient::getType() const
        {
            return (this->_type);
        }
    }
}