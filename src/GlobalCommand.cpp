//
// Created by Alexander on 09.04.2026.
//

#include "GlobalCommand.h"

int GlobalCommand::counter = 0;

GlobalCommand::GlobalCommand(GlobalCommandPrefix globalCommandPrefix, int param) {
    this->prefix = globalCommandPrefix;
    this->intValue = param;
    setId();
}

GlobalCommand::GlobalCommand(GlobalCommandPrefix globalCommandPrefix, bool enabled) {
    this->prefix = globalCommandPrefix;
    this->boolValue = enabled;
    setId();
}

GlobalCommand::GlobalCommand() {
    setId();
}

void GlobalCommand::setId(){
    this->id = this->counter;
    this->counter++;
}

int GlobalCommand::getId(){
    return id;
}

GlobalCommandPrefix GlobalCommand::getPrefix() const {
    return prefix;
}

float GlobalCommand::getValue() const {
    return floatValue;
}



void GlobalCommand::setFloatValue(float value) {
    this->floatValue = value;
}

void GlobalCommand::setPrefix(GlobalCommandPrefix globalCommandPrefix) {
    this->prefix = prefix;
}

void GlobalCommand::setIntValue(int value) {
    this->intValue = value;
}
