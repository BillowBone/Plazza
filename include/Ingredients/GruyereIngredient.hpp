/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** GruyereIngredient.hpp
*/

#ifndef GRUYEREINGREDIENT_HPP_
    #define GRUYEREINGREDIENT_HPP_

#include "AIngredient.hpp"

namespace plazza {
    namespace food {
        class GruyereIngredient : public AIngredient {
            public:
                GruyereIngredient();
                ~GruyereIngredient();
        };
    }
}

#endif /* !GRUYEREINGREDIENT_HPP_ */