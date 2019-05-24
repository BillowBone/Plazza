/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Kitchen.hpp
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

#include <vector>
#include <memory>
#include <mutex>
#include <thread>
#include <mqueue.h>
#include "IPizza.hpp"

namespace plazza {
    namespace kitchen {
        class Kitchen {
            public:
                Kitchen(int id, int nbCooks, int regeneration, float coeffBaking);
                ~Kitchen();
                void threadPool();
                void initMessageQueue();
            private:
                int id;
                int nbCooks;
                int nbPizzas;
                float coeffBaking;
                std::vector<std::unique_ptr<food::IPizza>> pizzas;
                std::vector<std::thread> cooks;
                mqd_t mqfdIn;
                mqd_t mqfdOut;
        };
    }
}

#endif /* !KITCHEN_HPP_ */