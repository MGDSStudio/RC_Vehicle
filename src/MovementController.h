
//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_MOVEMENTCONTROLLER_H
#define CMAKESFMLPROJECT_MOVEMENTCONTROLLER_H


#include "SinglePinActor.h"

class MovementController {
private:
    SinglePinActor* wheelForwardLeft;
    SinglePinActor* wheelForwardRight;
    SinglePinActor* wheelBackwardLeft;
    SinglePinActor* wheelBackwardRight;
};


#endif //CMAKESFMLPROJECT_MOVEMENTCONTROLLER_H
