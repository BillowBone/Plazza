/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** IIngredient.hpp
*/

#ifndef IINGREDIENT_HPP_
    #define IINGREDIENT_HPP_

namespace plazza {
    namespace food {
        enum IngredientType {
            Doe,
            Tomato,
            Gruyere,
            Ham,
            Mushrooms,
            Steak,
            Eggplant,
            GoatCheese,
            ChiefLove,
        };

        class IIngredient {
            public:
                virtual ~IIngredient() = default;
                virtual IngredientType getType() const = 0;
        };
    }
}

#endif /* !IINGREDIENT_HPP_ */
