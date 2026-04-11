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
        int messageNumber = messageCounter;
        messageNumber++;
        const std::string message = std::to_string(messageNumber)+' '+DEBUG+text;
        std::cout << message << std::endl;
    }

    static void custom(const std::string &prefix, const std::string &text) {
        int messageNumber = messageCounter;
        messageNumber++;
        const std::string message =  std::to_string(messageNumber)+' '+prefix+text;
        std::cout << message << std::endl;
    }


    static void criticalError(const std::string &prefix, const std::string &text) {
        int messageNumber = messageCounter;
        messageNumber++;
        const std::string message =  std::to_string(messageNumber)+' '+prefix+text;
        std::cerr << message << std::endl;
    }
private:
    inline static int messageCounter = 0;
};


#endif //CMAKESFMLPROJECT_LOGGER_H