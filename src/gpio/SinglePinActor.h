//
// Created by Alexander on 09.04.2026.
//

#ifndef RC_VEHICLE_WHEEL_H
#define RC_VEHICLE_WHEEL_H


#include "Pin.h"

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

    void setValue(float value) const;
    
    void enable(bool flag) const;

    void complete() const;


private:
    Pin* pin = nullptr;
    float direction;
};


#endif //RC_VEHICLE_WHEEL_H
