/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Mutex.hpp
*/

#ifndef MUTEX_HPP_
    #define MUTEX_HPP_

#include <mutex>

namespace plazza {
    namespace kitchen {
        class PlazzaMutex {
            public:
                PlazzaMutex();
                ~PlazzaMutex();
                void lock();
                void unlock();
                bool tryLock();
            private:
                std::mutex m;
        };
    }
}

#endif /* !MUTEX_HPP_ */