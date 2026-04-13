
//
// Created by gorod on 13.04.2026.
//

#include "WheelSignalsCalculatorSimple.h"
constexpr static float X_DISTANCE_BETWEEN_WHEELS = 200;
constexpr static float Y_DISTANCE_BETWEEN_WHEELS = 300;

void WheelSignalsCalculatorSimple::applyMoveForward(const float value) const {
    wheelForwardLeft->setForward(value);
    wheelForwardRight->setForward(value);
    wheelBackwardLeft->setForward(value);
    wheelBackwardRight->setForward(value);
}

void WheelSignalsCalculatorSimple::applyMoveBackward(const float value) const {
    wheelForwardLeft->setBackward(value);
    wheelForwardRight->setBackward(value);
    wheelBackwardLeft->setBackward(value);
    wheelBackwardRight->setBackward(value);
}

void WheelSignalsCalculatorSimple::applyRotationCw(const float value) const {
    wheelForwardLeft->setForward(value);
    wheelForwardRight->setBackward(value);
    wheelBackwardLeft->setForward(value);
    wheelBackwardRight->setBackward(value);
}

void WheelSignalsCalculatorSimple::applyRotationCcw(const float value) const {
    wheelForwardLeft->setBackward(value);
    wheelForwardRight->setForward(value);
    wheelBackwardLeft->setBackward(value);
    wheelBackwardRight->setForward(value);
}

void WheelSignalsCalculatorSimple::stopAll() const {
    wheelForwardLeft->stop();
    wheelForwardRight->stop();
    wheelBackwardLeft->stop();
    wheelBackwardRight->stop();
}
