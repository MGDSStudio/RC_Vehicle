//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_WHEELACTOR_H
#define CMAKESFMLPROJECT_WHEELACTOR_H


#include "SinglePinActor.h"

class WheelActor{

public:
    WheelActor(Pin *pinForward, Pin *pinBackward);
    WheelActor();

    ~WheelActor(){
        pinForward = nullptr;
        pinBackward = nullptr;
    }
    void setPinForward(Pin* pin);
    void setPinBackward(Pin* pin);
    void setForward(float relativeValue);
    void setBackward(float relativeValue);
    void stop();

private:
    Pin* pinForward = nullptr;
    Pin* pinBackward = nullptr;
    float direction;
};


#endif //CMAKESFMLPROJECT_WHEELACTOR_H
