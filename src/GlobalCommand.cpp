//
// Created by Alexander on 09.04.2026.
//

#include "GlobalCommand.h"

GlobalCommandPrefix GlobalCommand::getPrefix() const {
    return prefix;
}

float GlobalCommand::getValue() const {
    return floatValue;
}

GlobalCommand::GlobalCommand(GlobalCommandPrefix globalCommandPrefix, float param) {
    this->prefix = globalCommandPrefix;
    this->floatValue = param;
}

GlobalCommand::GlobalCommand() {

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
