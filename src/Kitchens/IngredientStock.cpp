/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** IngredientStock.cpp
*/

#include <iostream>
#include "IngredientStock.hpp"

namespace plazza {
    namespace kitchen {
        IngredientStock::IngredientStock()
        {
            this->regenerate = std::time(nullptr);
            for (int i = 0; i < 5; i++) {
                this->regenerateFood();
            }
        }

        IngredientStock::~IngredientStock()
        {
        }

        void IngredientStock::setRegeneration(int regTime)
        {
            this->regenerateTime = regTime;
        }

        void IngredientStock::regenerateFood()
        {
            this->stock.push_back(food::IngredientGenerator::generateFood(food::Doe));
            this->stock.push_back(food::IngredientGenerator::generateFood(food::Tomato));
            this->stock.push_back(food::IngredientGenerator::generateFood(food::Gruyere));
            this->stock.push_back(food::IngredientGenerator::generateFood(food::Ham));
            this->stock.push_back(food::IngredientGenerator::generateFood(food::Mushrooms));
            this->stock.push_back(food::IngredientGenerator::generateFood(food::Steak));
            this->stock.push_back(food::IngredientGenerator::generateFood(food::Eggplant));
            this->stock.push_back(food::IngredientGenerator::generateFood(food::GoatCheese));
            this->stock.push_back(food::IngredientGenerator::generateFood(food::ChiefLove));
        }

        void IngredientStock::checkRegeneration()
        {
            std::time_t res = std::time(nullptr);

            if ((res - this->regenerate) > (this->regenerateTime / 1000)) {
                this->regenerateFood();
                this->regenerate = std::time(nullptr);
            }
        }

        bool IngredientStock::getIngredients(food::PizzaType type)
        {
            std::vector<food::IngredientType> ingredients = this->getRecipe(type);

            for (int i = 0; i < ingredients.size(); i++) {
                for (int j = 0; j < this->stock.size(); j++) {
                    if (ingredients[i] == this->stock[j]->getType())
                        break;
                    if ((j + 1) == this->stock.size())
                        return (false);
                }
            }
            for (int k = 0; k < ingredients.size(); k++) {
                for (int l = 0; l < this->stock.size(); l++) {
                    if (ingredients[k] == this->stock[l]->getType()) {
                        this->stock.erase(this->stock.begin() + l);
                        break;
                    }
                }
            }
            this->checkRegeneration();
            return (true);
        }

        std::vector<food::IngredientType> IngredientStock::getRecipe(food::PizzaType type)
        {
            std::vector<food::IngredientType> ingredients;

            switch (type) {
                case food::PizzaType::Margarita:
                    ingredients.push_back(food::IngredientType::Doe);
                    ingredients.push_back(food::IngredientType::Tomato);
                    ingredients.push_back(food::IngredientType::Gruyere);
                    break;
                case food::PizzaType::Regina:
                    ingredients.push_back(food::IngredientType::Doe);
                    ingredients.push_back(food::IngredientType::Tomato);
                    ingredients.push_back(food::IngredientType::Gruyere);
                    ingredients.push_back(food::IngredientType::Ham);
                    ingredients.push_back(food::IngredientType::Mushrooms);
                    break;
                case food::PizzaType::Americana:
                    ingredients.push_back(food::IngredientType::Doe);
                    ingredients.push_back(food::IngredientType::Tomato);
                    ingredients.push_back(food::IngredientType::Gruyere);
                    ingredients.push_back(food::IngredientType::Steak);
                    break;
                case food::PizzaType::Fantasia:
                    ingredients.push_back(food::IngredientType::Doe);
                    ingredients.push_back(food::IngredientType::Tomato);
                    ingredients.push_back(food::IngredientType::Eggplant);
                    ingredients.push_back(food::IngredientType::GoatCheese);
                    ingredients.push_back(food::IngredientType::ChiefLove);
                    break;
            }
            return (ingredients);
        }
    }
}