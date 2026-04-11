//
// Created by Alexander on 11.04.2026.
//

#include "PinCommon.h"

#include "../Logger.h"
#ifdef IS_RPI
    #include <pigpio.h>
#endif

PinCommon::PinCommon(int number){
    this->hardwareNumber = number;
    this->numberAsString = std::to_string(number);
    this->debugTextPrefix = DEBUG_TEXT_PREFIX_COMMON+std::to_string(number);
    #ifdef IS_RPI
        gpioSetMode(hardwareNumber, PI_OUTPUT);
    #endif

}

void PinCommon::setValue(float value) {
    if (debug == true){
        std::string text = numberAsString+ " is set value: "+ std::to_string(value);
        Logger::custom(debugTextPrefix, text);
        int mapped = mapForPwm(value);
        #ifdef IS_RPI
            gpioPWM(hardwarePin, mapped);
        #endif
    }
}

void PinCommon::enable(bool flag) {
    if (debug){
        std::string text = numberAsString;// = DEBUG_TEXT_PREFIX + "set value: "+ std::to_string(value);
        if (flag) text.append(" enabled");
        else text.append(" disabled");
        #ifdef IS_RPI
                if (flag){
                    gpioPWM(hardwarePin, ENABLED_PWM_VALUE);
                }
                    else {
                        gpioPWM(hardwarePin, DISABLED_PWM_VALUE);
                    }
        #endif
        Logger::custom(debugTextPrefix, text);
    }
}

void PinCommon::complete(){
    #ifdef IS_RPI
        gpioPWM(hardwarePin, DISABLED_PWM_VALUE);
    #endif
}

int PinCommon::mapForPwm(float fromMinusOneUpToOne){
    float ostart = -1;
    float ostop = 1;
    float istart = ENABLED_PWM_VALUE;
    float istop = DISABLED_PWM_VALUE;
    float mapped = ostart + (ostop - ostart) * ((fromMinusOneUpToOne - istart) / (istop - istart));
    return (int)mapped;
}

/*
 (float value, float istart, float istop, float ostart, float ostop) {
        return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
    }
 */