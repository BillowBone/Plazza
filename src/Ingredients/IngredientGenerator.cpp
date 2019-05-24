/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** IngredientGenerator.cpp
*/

#include "IngredientGenerator.hpp"

namespace plazza {
    namespace food {
        std::unique_ptr<IIngredient> IngredientGenerator::generateFood(IngredientType ingredient)
        {
            switch (ingredient) {
                case Doe:
                    return (generateDoe());
                case Tomato:
                    return (generateTomato());
                case Gruyere:
                    return (generateGruyere());
                case Ham:
                    return (generateHam());
                case Mushrooms:
                    return (generateMushrooms());
                case Steak:
                    return (generateSteak());
                case Eggplant:
                    return (generateEggplant());
                case GoatCheese:
                    return (generateGoatCheese());
                case ChiefLove:
                    return (generateChiefLove());
                default:
                    return (generateDoe());
            }
        }

        std::unique_ptr<IIngredient> IngredientGenerator::generateDoe() {
            std::unique_ptr<IIngredient> tmp(new DoeIngredient());

            return (tmp);
        }

        std::unique_ptr<IIngredient> IngredientGenerator::generateTomato() {
            std::unique_ptr<IIngredient> tmp(new TomatoIngredient());

            return (tmp);
        }

        std::unique_ptr<IIngredient> IngredientGenerator::generateGruyere() {
            std::unique_ptr<IIngredient> tmp(new GruyereIngredient());

            return (tmp);
        }

        std::unique_ptr<IIngredient> IngredientGenerator::generateHam() {
            std::unique_ptr<IIngredient> tmp(new HamIngredient());

            return (tmp);
        }

        std::unique_ptr<IIngredient> IngredientGenerator::generateMushrooms() {
            std::unique_ptr<IIngredient> tmp(new MushroomsIngredient());

            return (tmp);
        }

        std::unique_ptr<IIngredient> IngredientGenerator::generateSteak() {
            std::unique_ptr<IIngredient> tmp(new SteakIngredient());

            return (tmp);
        }

        std::unique_ptr<IIngredient> IngredientGenerator::generateEggplant() {
            std::unique_ptr<IIngredient> tmp(new EggplantIngredient());

            return (tmp);
        }

        std::unique_ptr<IIngredient> IngredientGenerator::generateGoatCheese() {
            std::unique_ptr<IIngredient> tmp(new GoatCheeseIngredient());

            return (tmp);
        }

        std::unique_ptr<IIngredient> IngredientGenerator::generateChiefLove() {
            std::unique_ptr<IIngredient> tmp(new ChiefLoveIngredient());

            return (tmp);
        }
    }
}