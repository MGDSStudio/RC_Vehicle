//
// Created by Alexander on 11.04.2026.
//

#include "PinCommon.h"

#include "../Logger.h"
//#ifdef IS_RPI
    #include <pigpio.h>
//#endif

PinCommon::PinCommon(const int number){
    this->hardwareNumber = number;
    this->numberAsString = std::to_string(number);
    this->debugTextPrefix = DEBUG_TEXT_PREFIX_COMMON+std::to_string(number);
    #ifdef IS_RPI
        gpioSetMode(hardwareNumber, PI_OUTPUT);
        Logger::debug("PIN " + numberAsString+ " set as output ");
    #endif
    //Logger::debug()
}

void PinCommon::setValue(const float value) {
    int mapped = mapForPwm(value);
    bool appliedForPi = false;
   // #ifdef IS_RPI
        appliedForPi = true;
        gpioPWM(hardwareNumber, mapped);
        if (debug) {
            Logger::debug("GPIo");
        }
    //#endif
    if (debug){
        const std::string text = " is set value: "+ std::to_string(value) + "; mapped: " + std::to_string(mapped) + " applied for PI: " + std::to_string(appliedForPi);
        Logger::custom(debugTextPrefix, text);
    }
}

void PinCommon::enable(const bool flag) {
    float appliedForPi = false;
    //#ifdef IS_RPI
        appliedForPi = true;
        if (flag){
            gpioWrite(hardwareNumber, PI_HIGH);
            //gpioPWM(hardwarePin, ENABLED_PWM_VALUE);
        }
        else {
            gpioWrite(hardwareNumber, PI_LOW);
            //gpioPWM(hardwarePin, DISABLED_PWM_VALUE);
        }
    //#endif
    if (debug){
        std::string text = "";// = DEBUG_TEXT_PREFIX + "set value: "+ std::to_string(value);
        if (flag) text.append(" enabled. Applied for PI: " + std::to_string(appliedForPi));
        else text.append(" disabled. Applied for PI: " + std::to_string(appliedForPi));
        Logger::custom(debugTextPrefix, text);
    }
}

void PinCommon::complete(){
    //#ifdef IS_RPI
        gpioPWM(hardwareNumber, DISABLED_PWM_VALUE);
    //#endif
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