/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Cook.hpp
*/

#ifndef COOK_HPP_
    #define COOK_HPP_

#include <thread>
#include <mqueue.h>
#include "IPizza.hpp"
#include "Mutex.hpp"
#include "IngredientStock.hpp"
#include "Messenger.hpp"

namespace plazza {
    namespace kitchen {
        class Cook {
            public:
                static std::thread createCook(mqd_t mqfdIn, mqd_t mqfdOut, int id, int coeffBaking);
                static void cook(mqd_t mqfdIn, mqd_t mqfdOut, int id, float coeffBaking);
                static food::PizzaType interpretMessage(const std::string &cmd);
                static bool pickIngredients(food::PizzaType type);
                static void sendCommand(std::string command, mqd_t mqfdOut);
                static void bake(food::PizzaType type, float coeffBaking);
        };
    }
}

#endif /* !COOK_HPP_ */