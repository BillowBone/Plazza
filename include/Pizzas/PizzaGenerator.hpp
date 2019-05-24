/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** PizzaGenerator.hpp
*/

#ifndef PIZZAGENERATOR_HPP_
    #define PIZZAGENERATOR_HPP_

#include "MargaritaPizza.hpp"
#include "ReginaPizza.hpp"
#include "AmericanaPizza.hpp"
#include "FantasiaPizza.hpp"

namespace plazza {
    namespace food {
        class PizzaGenerator {
            public:
                static std::unique_ptr<IPizza> generatePizza(PizzaType type, PizzaSize size, int idCommand);
            private:
                static std::unique_ptr<IPizza> generateRegina(PizzaSize size, int idCommand);
                static std::unique_ptr<IPizza> generateMargarita(PizzaSize size, int idCommand);
                static std::unique_ptr<IPizza> generateAmericana(PizzaSize size, int idCommand);
                static std::unique_ptr<IPizza> generateFantasia(PizzaSize size, int idCommand);
        };
    }
}

#endif /* !PIZZAGENERATOR_HPP_ */