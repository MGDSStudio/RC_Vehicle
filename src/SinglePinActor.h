//
// Created by Alexander on 09.04.2026.
//

#ifndef RC_VEHICLE_WHEEL_H
#define RC_VEHICLE_WHEEL_H


#include "gpio/Pin.h"

class SinglePinActor {

private:
    Pin* pinForward;
    float direction;
};


#endif //RC_VEHICLE_WHEEL_H
