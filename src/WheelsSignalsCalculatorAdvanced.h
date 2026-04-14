//
// Created by gorod on 14.04.2026.
//

#ifndef CMAKESFMLPROJECT_WHEELSIGNALSCALCULATORADVANCED_H
#define CMAKESFMLPROJECT_WHEELSIGNALSCALCULATORADVANCED_H

#include "WheelActor.h"

enum class ActivationType{
    ANALOG, DIGITAL, NO_DATA
};
class WheelsSignalsCalculatorAdvanced {

public:
WheelsSignalsCalculatorAdvanced(WheelActor* wheelForwardLeft, WheelActor* wheelForwardRight, WheelActor* wheelBackwardLeft, WheelActor* wheelBackwardRight) {
    this->wheelForwardLeft = wheelForwardLeft;
    this->wheelForwardRight = wheelForwardRight;
    this->wheelBackwardLeft = wheelBackwardLeft;
    this->wheelBackwardRight = wheelBackwardRight;
}
void applyMoveForward(float value) const;

void applyMoveBackward(float value) const;

void applyRotationCw(float value) const;

void applyRotationCcw(float value) const;

void stopAll() const;

private:
    WheelActor* wheelForwardLeft;
    WheelActor* wheelForwardRight;
    WheelActor* wheelBackwardLeft;
    WheelActor* wheelBackwardRight;
    ActivationType actualActivationType = ActivationType::NO_DATA;
    static constexpr int STOP_VALUE = 0;
};


#endif //CMAKESFMLPROJECT_WHEELSIGNALSCALCULATORADVANCED_H