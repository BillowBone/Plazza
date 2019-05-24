/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Kitchen.cpp
*/

#include <iostream>
#include <cstdlib>
#include <chrono>
#include "IIngredient.hpp"
#include "Kitchen.hpp"
#include "Cook.hpp"
#include "Exceptions.hpp"

namespace plazza {
    namespace kitchen {
        Kitchen::Kitchen(int id, int nbCooks, int regeneration, float coeffBaking)
        {
            this->id = id;
            this->nbCooks = nbCooks;
            this->nbPizzas = 0;
            this->coeffBaking = coeffBaking;
            this->initMessageQueue();
            for (int i = 0; i < this->nbCooks; i++) {
                this->cooks.push_back(Cook::createCook(this->mqfdIn, this->mqfdOut, regeneration, this->coeffBaking));
            }
            this->threadPool();
        }

        Kitchen::~Kitchen()
        {
        }

        void Kitchen::threadPool()
        {
            for (int i = 0; i < this->nbCooks; i++) {
                this->cooks[i].join();
            }
            std::_Exit(0);
        }

        void Kitchen::initMessageQueue()
        {
            struct mq_attr attr;
            std::string name("/plazza" + std::to_string(this->id) + "IN");

            attr.mq_maxmsg = 10;
            attr.mq_msgsize = 20;
            this->mqfdIn = mq_open(name.c_str(), O_RDWR | O_CREAT, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH), &attr);
            if (this->mqfdIn == -1) {
                throw OpenQueueException("Opening message queue failed.", "Kitchen");
            }
            name.clear();
            name = "/plazza" + std::to_string(this->id) + "OUT";
            this->mqfdOut = mq_open(name.c_str(), O_RDWR | O_CREAT, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH), &attr);
            if (this->mqfdOut == -1) {
                throw OpenQueueException("Opening message queue failed.", "Kitchen");
            }
        }
    }
}