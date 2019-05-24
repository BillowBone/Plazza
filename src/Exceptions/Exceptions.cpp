/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Exceptions.cpp
*/

#include "Exceptions.hpp"

namespace plazza {
    PlazzaException::PlazzaException(const std::string &message, const std::string &component) noexcept :
        std::exception(), message(message), component(component)
    {
        std::cerr << "Error: " << this->where() << ": " << this->what() << std::endl;
    }

    PlazzaException::~PlazzaException()
    {
    }

    const char *PlazzaException::what() const noexcept
    {
        return (message.c_str());
    }

    const char *PlazzaException::where() const noexcept
    {
        return (component.c_str());
    }

    OpenQueueException::OpenQueueException(const std::string &message, const std::string &component) noexcept : PlazzaException(message, component)
    {
    }

    MessageQueueException::MessageQueueException(const std::string &message, const std::string &component) noexcept : PlazzaException(message, component)
    {
    }

    InvalidQueueException::InvalidQueueException(const std::string &message, const std::string &component) noexcept : PlazzaException(message, component)
    {
    }

    InvalidCommandException::InvalidCommandException(const std::string &message, const std::string &component) noexcept : PlazzaException(message, component)
    {
    }
}