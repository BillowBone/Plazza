/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Exceptions.hpp
*/

#ifndef EXCEPTIONS_HPP_
    #define EXCEPTIONS_HPP_

#include <exception>
#include <iostream>

namespace plazza {
    class PlazzaException : public std::exception {
        public:
            PlazzaException(const std::string &message = "Unknown",
                const std::string &component = "Unknown") noexcept;
            ~PlazzaException();
            const char *what() const noexcept;
            const char *where() const noexcept;
        protected:
            const std::string &message;
            const std::string &component;
    };

    class OpenQueueException : public PlazzaException {
        public:
            OpenQueueException(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
    };

    class MessageQueueException : public PlazzaException {
        public:
            MessageQueueException(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
    };

    class InvalidQueueException : public PlazzaException {
        public:
            InvalidQueueException(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
    };

    class InvalidCommandException : public PlazzaException {
        public:
            InvalidCommandException(const std::string &message = "Unknown",
                        const std::string &component = "Unknown") noexcept;
    };
}

#endif /* !EXCEPTIONS_HPP_ */