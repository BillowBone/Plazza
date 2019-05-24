/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** SteakIngredient.hpp
*/

#ifndef STEAKINGREDIENT_HPP_
    #define STEAKINGREDIENT_HPP_

#include "AIngredient.hpp"

namespace plazza {
    namespace food {
        class SteakIngredient : public AIngredient {
            public:
                SteakIngredient();
                ~SteakIngredient();
        };
    }
}

#endif /* !STEAKINGREDIENT_HPP_ */
