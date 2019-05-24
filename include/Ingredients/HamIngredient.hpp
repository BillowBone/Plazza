/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** HamIngredient.hpp
*/

#ifndef HAMINGREDIENT_HPP_
    #define HAMINGREDIENT_HPP_

#include "AIngredient.hpp"

namespace plazza {
    namespace food {
        class HamIngredient : public AIngredient {
            public:
                HamIngredient();
                ~HamIngredient();
        };
    }
}

#endif /* !HAMINGREDIENT_HPP_ */
