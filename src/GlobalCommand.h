//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_GLOBALCOMMAND_H
#define CMAKESFMLPROJECT_GLOBALCOMMAND_H

#include "GlobalCommandPrefix.h"
#include "Constants.h"
/*enum class Prefix{
    FORWARD, BACKWARD, LEFT, RIGHT, NOISE
};*/
class GlobalCommand {

public:
    GlobalCommand();

    GlobalCommand(GlobalCommandPrefix globalCommandPrefix, float param);

    GlobalCommandPrefix getPrefix() const;

    float getValue() const;

    void setPrefix(GlobalCommandPrefix globalCommandPrefix);

    void setFloatValue(float value);

    void setIntValue(int value);

private:
    GlobalCommandPrefix prefix;
    float floatValue;
    int intValue;
};


#endif //CMAKESFMLPROJECT_GLOBALCOMMAND_H
