/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** IngredientGenerator.hpp
*/

#ifndef INGREDIENTGENERATOR_HPP_
    #define INGREDIENTGENERATOR_HPP_

#include <memory>
#include "ChiefLoveIngredient.hpp"
#include "DoeIngredient.hpp"
#include "EggplantIngredient.hpp"
#include "GoatCheeseIngredient.hpp"
#include "GruyereIngredient.hpp"
#include "HamIngredient.hpp"
#include "MushroomsIngredient.hpp"
#include "SteakIngredient.hpp"
#include "TomatoIngredient.hpp"

namespace plazza {
    namespace food {
        class IngredientGenerator {
            public:
                static std::unique_ptr<IIngredient> generateFood(IngredientType ingredient);
            private:
                static std::unique_ptr<IIngredient> generateDoe();
                static std::unique_ptr<IIngredient> generateTomato();
                static std::unique_ptr<IIngredient> generateGruyere();
                static std::unique_ptr<IIngredient> generateHam();
                static std::unique_ptr<IIngredient> generateMushrooms();
                static std::unique_ptr<IIngredient> generateSteak();
                static std::unique_ptr<IIngredient> generateEggplant();
                static std::unique_ptr<IIngredient> generateGoatCheese();
                static std::unique_ptr<IIngredient> generateChiefLove();
        };
    }
}

#endif /* !INGREDIENTGENERATOR_HPP_ */
