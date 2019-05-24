/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** AIngredient.hpp
*/

#ifndef AINGREDIENT_HPP_
    #define AINGREDIENT_HPP_

#include "IIngredient.hpp"

namespace plazza {
    namespace food {
        class AIngredient : public IIngredient {
            public:
                AIngredient();
                ~AIngredient();
                IngredientType getType() const;
            protected:
                IngredientType _type;
        };
    }
}

#endif /* !AINGREDIENT_HPP_ */
