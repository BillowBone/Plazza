/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** IPizza.hpp
*/

#ifndef IPIZZA_HPP_
    #define IPIZZA_HPP_

namespace plazza {
    namespace food {
        enum PizzaType {
            None = 0,
            Regina = 1,
            Margarita = 2,
            Americana = 4,
            Fantasia = 8
        };

        enum PizzaSize {
            Null = 0,
            S = 1,
            M = 2,
            L = 4,
            XL = 8,
            XXL = 16
        };

        class IPizza {
            public:
                virtual ~IPizza() = default;
                virtual PizzaType getType() const = 0;
                virtual PizzaSize getSize() const = 0;
                virtual int getBakingTime() const = 0;
                virtual int getIdCommand() const = 0;
                virtual void dump() const = 0;
        };
    }
}

#endif /* !IPIZZA_HPP_ */
