//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_GLOBALCOMMAND_H
#define CMAKESFMLPROJECT_GLOBALCOMMAND_H

#include "GlobalCommandPrefix.h"

/*enum class Prefix{
    FORWARD, BACKWARD, LEFT, RIGHT, NOISE
};*/
class GlobalCommand {

public:
    GlobalCommand(GlobalCommandPrefix globalCommandPrefix, float param);

    GlobalCommandPrefix getPrefix() const;

    float getValue() const;

private:
    GlobalCommandPrefix prefix;
    float value;
};


#endif //CMAKESFMLPROJECT_GLOBALCOMMAND_H
