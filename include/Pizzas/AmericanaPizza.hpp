/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** AmericanaPizza.hpp
*/

#ifndef AMERICANAPIZZA_HPP_
    #define AMERICANAPIZZA_HPP_

#include "APizza.hpp"

namespace plazza {
    namespace food {
        class AmericanaPizza : public APizza {
            public:
                AmericanaPizza(PizzaSize size, int idCommand);
                ~AmericanaPizza();
        };
    }
}

#endif /* !AMERICANAPIZZA_HPP_ */
