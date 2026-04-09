//
// Created by Alexander on 09.04.2026.
//


#include "SoftwarePin.h"
#include "Logger.h"


void SoftwarePin::setValue(float value) {
    std::string text = numberAsString+ " is set value: "+ std::to_string(value);
    Logger::custom(DEBUG_TEXT_PREFIX, text);
}

void SoftwarePin::enable(bool flag) {
    std::string text = numberAsString;// = DEBUG_TEXT_PREFIX + "set value: "+ std::to_string(value);
    if (flag) text.append(" enabled");
    else text.append(" disabled");
    Logger::custom(DEBUG_TEXT_PREFIX, text);
}
