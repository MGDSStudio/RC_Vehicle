//
// Created by Alexander on 09.04.2026.
//

#include "WheelActor.h"


WheelActor::WheelActor(Pin *pinForward, Pin *pinBackward) : pinForward(pinForward), pinBackward(pinBackward) {
    
}

WheelActor::WheelActor() {

}


void WheelActor::setForward(float relativeValue) {
    pinForward->setValue(relativeValue);
    this->direction = relativeValue;
}

void WheelActor::setBackward(float relativeValue) {
    pinBackward->setValue(relativeValue);
    this->direction = relativeValue;
}

void WheelActor::stop() {
    pinForward->enable(false);
    pinBackward->enable(false);
    this->direction = 0;
}

void WheelActor::setPinForward(Pin* pin){
    this->pinForward = pin;
}

void WheelActor::setPinBackward(Pin* pin){
    this->pinBackward = pin;
}
