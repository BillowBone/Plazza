/*
** EPITECH PROJECT, 2019
** PSU - Concurrent Programming - Plazza
** File description:
** Logger.cpp
*/

#include <chrono>
#include <fstream>
#include "Logger.hpp"

namespace plazza {
    void Logger::newEntry(const std::string &entry)
    {
        std::ofstream file("plazza.log", std::ios_base::app);
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        Logger::displayNumTwoDigits(file, now->tm_mday);
        file << "-";
        Logger::displayNumTwoDigits(file, now->tm_mon + 1);
        file << "-" << (now->tm_year + 1900) << " (";
        Logger::displayNumTwoDigits(file, now->tm_hour);
        file << ":";
        Logger::displayNumTwoDigits(file, now->tm_min);
        file << ":";
        Logger::displayNumTwoDigits(file, now->tm_sec);
        file << ") : " << entry << std::endl;
    }

    void Logger::displayNumTwoDigits(std::ofstream &file, int num)
    {
        if (num < 10)
            file << "0" << num;
        else
            file << num;
    }
}