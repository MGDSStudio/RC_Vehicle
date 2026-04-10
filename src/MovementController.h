
//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_MOVEMENTCONTROLLER_H
#define CMAKESFMLPROJECT_MOVEMENTCONTROLLER_H


#include "SinglePinActor.h"
#include "WheelActor.h"
#include "gpio/SoftwarePin.h"

class MovementController {

public:
    MovementController();
    void update();

private:
    WheelActor wheelForwardLeft;
    WheelActor wheelForwardRight;
    WheelActor wheelBackwardLeft;
    WheelActor wheelBackwardRight;
};


#endif //CMAKESFMLPROJECT_MOVEMENTCONTROLLER_H
