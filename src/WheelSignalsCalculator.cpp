//
// Created by mgdsstudio on 12.04.2026.
//

#include "WheelSignalsCalculator.h"

void WheelSignalsCalculator::applyMoveForward(const float value) const {
    wheelForwardLeft->setForward(value);
    wheelForwardRight->setForward(value);
    wheelBackwardLeft->setForward(value);
    wheelBackwardRight->setForward(value);
}

void WheelSignalsCalculator::applyMoveBackward(const float value) const {
    wheelForwardLeft->setBackward(value);
    wheelForwardRight->setBackward(value);
    wheelBackwardLeft->setBackward(value);
    wheelBackwardRight->setBackward(value);
}

void WheelSignalsCalculator::applyRotationCw(const float value) const {
    wheelForwardLeft->setForward(value);
    wheelForwardRight->setBackward(value);
    wheelBackwardLeft->setForward(value);
    wheelBackwardRight->setBackward(value);
}

void WheelSignalsCalculator::applyRotationCcw(const float value) const {
    wheelForwardLeft->setBackward(value);
    wheelForwardRight->setForward(value);
    wheelBackwardLeft->setBackward(value);
    wheelBackwardRight->setForward(value);
}

void WheelSignalsCalculator::stopAll() const {
    wheelForwardLeft->stop();
    wheelForwardRight->stop();
    wheelBackwardLeft->stop();
    wheelBackwardRight->stop();
}
