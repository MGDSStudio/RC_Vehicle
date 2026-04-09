//
// Created by Alexander on 09.04.2026.
//

#include "GlobalCommand.h"

GlobalCommandPrefix GlobalCommand::getPrefix() const {
    return prefix;
}

float GlobalCommand::getValue() const {
    return value;
}

GlobalCommand::GlobalCommand(GlobalCommandPrefix globalCommandPrefix, float param) {
    this->prefix = globalCommandPrefix;
    this->value = param;
}
