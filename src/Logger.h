//
// Created by gorod on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_LOGGER_H
#define CMAKESFMLPROJECT_LOGGER_H
#include <iostream>
#include <ostream>
#include <string>

static const std::string DEBUG = "DEBUG: ";

class Logger {




public:
    static void debug(const std::string &text) {
        const std::string message = DEBUG+text;
        std::cout << message << std::endl;
    }
};


#endif //CMAKESFMLPROJECT_LOGGER_H