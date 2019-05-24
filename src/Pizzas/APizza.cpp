/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** APizza.cpp
*/

#include <iostream>
#include "APizza.hpp"

namespace plazza {
    namespace food {
        APizza::APizza()
        {
        }

        APizza::~APizza()
        {
        }

        PizzaType APizza::getType() const
        {
            return (this->_type);
        }

        PizzaSize APizza::getSize() const
        {
            return (this->_size);
        }

        int APizza::getBakingTime() const
        {
            return (this->_bakingTime);
        }

        int APizza::getIdCommand() const
        {
            return (this->_idCommand);
        }

        void APizza::dump() const
        {
            this->dumpPizza();
            this->dumpSize();
            std::cout << "Its baking time is " << std::to_string(this->_bakingTime) << "s" << std::endl;
            this->dumpIngredients();
        }

        void APizza::dumpPizza() const
        {
            std::cout << "This pizza is a ";
            switch (this->_type) {
                case Margarita:
                    std::cout << "Margarita";
                    break;
                case Regina:
                    std::cout << "Regina";
                    break;
                case Americana:
                    std::cout << "Americana";
                    break;
                case Fantasia:
                    std::cout << "Fantasia";
                    break;
            }
            std::cout << std::endl;
        }

        void APizza::dumpSize() const
        {
            std::cout << "It is of size ";
            switch (this->_size) {
                case S:
                    std::cout << "S";
                    break;
                case M:
                    std::cout << "M";
                    break;
                case L:
                    std::cout << "L";
                    break;
                case XL:
                    std::cout << "XL";
                    break;
                case XXL:
                    std::cout << "XXL";
                    break;
            }
            std::cout << std::endl;
        }

        void APizza::dumpIngredients() const
        {
            std::cout << "It contains:" << std::endl; 
            for (int i = 0; i < this->_ingredients.size(); i++) {
                switch (this->_ingredients[i]->getType()) {
                    case Doe:
                        std::cout << "\tDoe";
                        break;
                    case Tomato:
                        std::cout << "\tTomato";
                        break;
                    case Gruyere:
                        std::cout << "\tGruyere";
                        break;
                    case Ham:
                        std::cout << "\tHam";
                        break;
                    case Mushrooms:
                        std::cout << "\tMushrooms";
                        break;
                    case Steak:
                        std::cout << "\tSteak";
                        break;
                    case Eggplant:
                        std::cout << "\tEggplant";
                        break;
                    case GoatCheese:
                        std::cout << "\tGoat Cheese";
                        break;
                    case ChiefLove:
                        std::cout << "\tChief Love";
                        break;
                }
                std::cout << std::endl;
            }
        }
    }
}
