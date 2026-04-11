//
// Created by Alexander on 09.04.2026.
//

#ifndef RC_VEHICLE_WHEEL_H
#define RC_VEHICLE_WHEEL_H


#include "gpio/Pin.h"

class SinglePinActor {

public:
    SinglePinActor(Pin* pin){
        this->pin = pin;
    }

    SinglePinActor(){

    }

    ~SinglePinActor(){
        this->pin = nullptr;
    }

    void setPin(Pin* pin);

    void setValue(float value);
    
    void enable(bool flag);

    void complete();


private:
    Pin* pin = nullptr;
    float direction;
};


#endif //RC_VEHICLE_WHEEL_H
