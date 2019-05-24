/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Messenger.hpp
*/

#ifndef MESSENGER_HPP_
    #define MESSENGER_HPP_

#include <vector>
#include <string>
#include <cstdio>
#include <mqueue.h>
#include <time.h>

#define PMODE 0655

namespace plazza {
    namespace ipc {
        class Messenger {
            public:
                Messenger();
                ~Messenger();
                void addQueue(int idKitchen);
                void sendMessageToKitchen(int idKitchen, const std::string message);
                int receiveMessageFromKitchen(int idKitchen, std::string &buffer);
                static void sendMessageToReception(mqd_t descriptor, const std::string message);
                static void receiveMessageFromReception(mqd_t descriptor, std::string &buffer);
            private:
                int nbQueues;
                std::vector<std::pair<int, mqd_t>> ins;
                std::vector<std::pair<int, mqd_t>> outs;
                int getQueueId(int idKitchen, int mode);
        };
    }
}

#endif /* !MESSENGER_HPP_ */