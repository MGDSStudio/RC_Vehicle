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

    GlobalCommand(GlobalCommandPrefix globalCommandPrefix, int param);

    GlobalCommand(GlobalCommandPrefix globalCommandPrefix, bool enabled);

    GlobalCommandPrefix getPrefix() const;

    [[nodiscard]] float getFloatValue() const {
        return floatValue;
    }



    void setPrefix(GlobalCommandPrefix globalCommandPrefix);

    void setFloatValue(float value);

    void setBoolValue(bool value) {
        this->boolValue = value;
    }

    void setIntValue(int value);

    int getId() const;

    bool getBool() const;

private:
    GlobalCommandPrefix prefix = GlobalCommandPrefix::NO_DATA;
    float floatValue;
    int intValue = 0;
    bool boolValue = true;
    int id;

    static int counter;

    void setId();
};


#endif //CMAKESFMLPROJECT_GLOBALCOMMAND_H
