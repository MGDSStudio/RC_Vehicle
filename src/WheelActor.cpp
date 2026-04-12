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
    pinBackward->enable(false);
    hardwarePinForward->setValue(relativeValue);
    hardwarePinBackward->enable(false);
    this->direction = relativeValue;
}

void WheelActor::setBackward(float relativeValue) {
    pinForward->enable(false);
    pinBackward->setValue(relativeValue);
    hardwarePinForward->enable(false);
    hardwarePinBackward->setValue(relativeValue);
    this->direction = relativeValue;
}

void WheelActor::stop() {
    pinForward->enable(false);
    pinBackward->enable(false);
    hardwarePinForward->enable(false);
    hardwarePinBackward->enable(false);
    this->direction = 0;
}

void WheelActor::setPinForward(Pin* pin){
    this->pinForward = pin;
}

void WheelActor::setPinBackward(Pin* pin){
    this->pinBackward = pin;
}

void WheelActor::setHardwarePinForward(PinCommon *pin) {
    this->hardwarePinForward = pin;
}

void WheelActor::setHardwarePinBackward(PinCommon *pin) {
    this->hardwarePinBackward = pin;
}

