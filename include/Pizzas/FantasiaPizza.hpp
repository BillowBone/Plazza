/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** FantasiaPizza.hpp
*/

#ifndef FANTASIAPIZZA_HPP_
    #define FANTASIAPIZZA_HPP_

#include "APizza.hpp"

namespace plazza {
    namespace food {
        class FantasiaPizza : public APizza {
            public:
                FantasiaPizza(PizzaSize size, int idCommand);
                ~FantasiaPizza();
        };
    }
}

#endif /* !FANTASIAPIZZA_HPP_ */
