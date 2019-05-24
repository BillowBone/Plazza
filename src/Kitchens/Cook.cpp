/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Cook.cpp
*/

#include "Cook.hpp"

namespace plazza {
    namespace kitchen {
        static IngredientStock stock;
        static PlazzaMutex lock_bowl;
        static PlazzaMutex lock_message_in;
        static PlazzaMutex lock_message_out;

        std::thread Cook::createCook(mqd_t mqfdIn, mqd_t mqfdOut, int regeneration, int coeffBaking)
        {
            std::thread tmp(&Cook::cook, mqfdIn, mqfdOut, regeneration, coeffBaking);

            return (tmp);
        }

        void Cook::cook(mqd_t mqfdIn, mqd_t mqfdOut, int regeneration, float coeffBaking)
        {
            std::string buffer;
            std::string command;

            stock.setRegeneration(regeneration);
            while (1) {
                lock_message_in.lock();
                ipc::Messenger::receiveMessageFromReception(mqfdIn, buffer);
                command = buffer;
                lock_message_in.unlock();
                if (buffer.compare("EXIT") == 0) {
                    Cook::sendCommand(command, mqfdOut);
                    break;
                }
                while (!Cook::pickIngredients(Cook::interpretMessage(buffer)));
                Cook::bake(Cook::interpretMessage(buffer), coeffBaking);
                Cook::sendCommand(command, mqfdOut);
            }
        }

        food::PizzaType Cook::interpretMessage(const std::string &cmd)
        {
            food::PizzaType parsed;

            switch (cmd[0]) {
                case '1':
                    parsed = food::PizzaType::Regina;
                    break;
                case '2':
                    parsed = food::PizzaType::Margarita;
                    break;
                case '4':
                    parsed = food::PizzaType::Americana;
                    break;
                case '8':
                    parsed = food::PizzaType::Fantasia;
                    break;
            }
            return (parsed);
        }

        bool Cook::pickIngredients(food::PizzaType type)
        {
            bool ret = false;

            lock_bowl.lock();
            stock.checkRegeneration();
            ret = stock.getIngredients(type);
            lock_bowl.unlock();
            return (ret);
        }

        void Cook::sendCommand(std::string command, mqd_t mqfdOut)
        {
            std::string response(command + " OK");

            lock_message_out.lock();
            ipc::Messenger::sendMessageToReception(mqfdOut, response);
            lock_message_out.unlock();
        }

        void Cook::bake(food::PizzaType type, float coeffBaking)
        {
            int timeBake = 0;

            switch (type) {
                case food::PizzaType::Margarita:
                    timeBake = 1000;
                    break;
                case food::PizzaType::Regina:
                    timeBake = 2000;
                    break;
                case food::PizzaType::Americana:
                    timeBake = 2000;
                    break;
                case food::PizzaType::Fantasia:
                    timeBake = 4000;
                    break;
            }
            timeBake *= coeffBaking;
            std::this_thread::sleep_for(std::chrono::milliseconds(timeBake));
        }
    }
}