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

    GlobalCommand(GlobalCommandPrefix globalCommandPrefix, int intParam, float floatParam);

    GlobalCommand(GlobalCommandPrefix globalCommandPrefix, int param);

    GlobalCommand(GlobalCommandPrefix globalCommandPrefix, bool enabled);

    GlobalCommandPrefix getPrefix() const;

    float getValue() const;

    void setPrefix(GlobalCommandPrefix globalCommandPrefix);

    void setFloatValue(float value);

    void setIntValue(int value);

    int getId();

    bool getBool();

private:
    GlobalCommandPrefix prefix;
    float floatValue;
    int intValue;
    bool boolValue;
    int id;

    static int counter;

    void setId();
};


#endif //CMAKESFMLPROJECT_GLOBALCOMMAND_H
