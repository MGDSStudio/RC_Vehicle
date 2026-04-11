//
// Created by Alexander on 09.04.2026.
//

#include "SinglePinActor.h"




void SinglePinActor::setPin(Pin* pin){
    this->pin = pin;
}

void SinglePinActor::setValue(float value) const {
    pin->setValue(value);
}
    
void SinglePinActor::enable(bool flag) const {
    pin->enable(flag);
}

void SinglePinActor::complete() const {
    pin->complete();
}
