/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** MargaritaPizza.hpp
*/

#ifndef MARGARITAPIZZA_HPP_
    #define MARGARITAPIZZA_HPP_

#include "APizza.hpp"

namespace plazza {
    namespace food {
        class MargaritaPizza : public APizza {
            public:
                MargaritaPizza(PizzaSize size, int idCommand);
                ~MargaritaPizza();
        };
    }
}

#endif /* !MARGARITAPIZZA_HPP_ */
