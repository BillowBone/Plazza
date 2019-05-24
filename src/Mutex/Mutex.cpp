/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Prgramming - Plazza
** File description:
** Mutex.cpp
*/

#include <iostream>
#include "Mutex.hpp"

namespace plazza {
    namespace kitchen {
        PlazzaMutex::PlazzaMutex()
        {
        }

        PlazzaMutex::~PlazzaMutex()
        {
        }

        void PlazzaMutex::lock()
        {
            this->m.lock();
        }

        void PlazzaMutex::unlock()
        {
            this->m.unlock();
        }

        bool PlazzaMutex::tryLock()
        {
            return (this->m.try_lock());
        }
    }
}