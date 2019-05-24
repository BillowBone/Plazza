/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** main.cpp
*/

#include <iostream>
#include <mqueue.h>
#include <thread>
#include <exception>
#include "Parser.hpp"
#include "Exceptions.hpp"

int main(int argc, char *argv[])
{
    try {
        plazza::Parser parser(argc, argv);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return (84);
    }
    return (0);
}