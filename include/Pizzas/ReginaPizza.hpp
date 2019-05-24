/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** ReginaPizza.hpp
*/

#ifndef REGINAPIZZA_HPP_
    #define REGINAPIZZA_HPP_

#include "APizza.hpp"

namespace plazza {
    namespace food {
        class ReginaPizza : public APizza {
            public:
                ReginaPizza(PizzaSize size, int idCommand);
                ~ReginaPizza();
        };
    }
}

#endif /* !REGINAPIZZA_HPP_ */
