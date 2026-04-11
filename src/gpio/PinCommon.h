//
// Created by Alexander on 11.04.2026.
//

#ifndef CMAKESFMLPROJECT_PINCOMMON_H
#define CMAKESFMLPROJECT_PINCOMMON_H

#include <string>

class PinCommon {
public:
    PinCommon(int number);
    virtual ~PinCommon() = default;
    virtual void setValue(float value) = 0;
    virtual void enable(bool flag) = 0;
    virtual void complete() = 0;

protected:
    int hardwareNumber;
    std::string name;
    std::string numberAsString;
    const std::string DEBUG_TEXT_PREFIX_COMMON = "PIN ";
    std::string debugTextPrefix;
    const bool debug = true;
    const int ENABLED_PWM_VALUE = 0;
    const int DISABLED_PWM_VALUE = 255;

    int mapForPwm(float fromMinusOneUpToOne);
};




#endif //CMAKESFMLPROJECT_PINCOMMON_H
