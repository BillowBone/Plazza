/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** IngredientStock.hpp
*/

#ifndef INGREDIENTSTOCK_HPP_
    #define INGREDIENTSTOCK_HPP_

#include <vector>
#include <memory>
#include <chrono>
#include "IIngredient.hpp"
#include "IPizza.hpp"
#include "IngredientGenerator.hpp"

namespace plazza {
    namespace kitchen {
        class IngredientStock {
        public:
            IngredientStock();
            ~IngredientStock();
            void setRegeneration(int regTime);
            void regenerateFood();
            void checkRegeneration();
            bool getIngredients(food::PizzaType type);
        private:
            int regenerateTime;
            std::time_t regenerate;
            std::vector<std::unique_ptr<food::IIngredient>> stock;
            std::vector<food::IngredientType> getRecipe(food::PizzaType type);
        };
    }
}

#endif /* !INGREDIENTSTOCK_HPP_ */