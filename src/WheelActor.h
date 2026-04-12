//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_WHEELACTOR_H
#define CMAKESFMLPROJECT_WHEELACTOR_H


#include "gpio/SinglePinActor.h"
#include "magic_enum/magic_enum.hpp"

class WheelActor{

public:
    WheelActor(Pin *pinForward, Pin *pinBackward);
    WheelActor();

    ~WheelActor(){
        delete pinForward;
        delete pinBackward;
        delete hardwarePinForward;
        delete hardwarePinBackward;
    }
    void setPinForward(Pin* pin);
    void setPinBackward(Pin* pin);
    void setHardwarePinForward(PinCommon* pin);
    void setHardwarePinBackward(PinCommon* pin);

    void setForward(float relativeValue);
    void setBackward(float relativeValue);
    void stop();

private:
    Pin* pinForward = nullptr;
    Pin* pinBackward = nullptr;
    PinCommon* hardwarePinForward = nullptr;
    PinCommon* hardwarePinBackward = nullptr;
    float direction;
};


#endif //CMAKESFMLPROJECT_WHEELACTOR_H
