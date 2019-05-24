/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** PizzaGenerator.cpp
*/

#include <iostream>
#include "PizzaGenerator.hpp"

namespace plazza {
    namespace food {
        std::unique_ptr<IPizza> PizzaGenerator::generatePizza(PizzaType pizza, PizzaSize size, int idCommand) {
            switch (pizza) {
                case Margarita:
                    return (generateMargarita(size, idCommand));
                case Regina:
                    return (generateRegina(size, idCommand));
                case Americana:
                    return (generateAmericana(size, idCommand));
                case Fantasia:
                    return (generateFantasia(size, idCommand));
                default:
                    return (nullptr);
            }
        }

        std::unique_ptr<IPizza> PizzaGenerator::generateMargarita(PizzaSize size, int idCommand) {
            std::unique_ptr<IPizza> tmp(new MargaritaPizza(size, idCommand));

            return (tmp);
        }

        std::unique_ptr<IPizza> PizzaGenerator::generateRegina(PizzaSize size, int idCommand) {
            std::unique_ptr<IPizza> tmp(new ReginaPizza(size, idCommand));

            return (tmp);
        }

        std::unique_ptr<IPizza> PizzaGenerator::generateAmericana(PizzaSize size, int idCommand) {
            std::unique_ptr<IPizza> tmp(new AmericanaPizza(size, idCommand));

            return (tmp);
        }

        std::unique_ptr<IPizza> PizzaGenerator::generateFantasia(PizzaSize size, int idCommand) {
            std::unique_ptr<IPizza> tmp(new FantasiaPizza(size, idCommand));

            return (tmp);
        }
    }
}