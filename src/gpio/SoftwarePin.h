//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_SOFTWAREPIN_H
#define CMAKESFMLPROJECT_SOFTWAREPIN_H

#include "Pin.h"

class SoftwarePin : public Pin{

    public:    
    SoftwarePin(int pinNumber) : Pin(pinNumber){

    };
    virtual ~SoftwarePin() override{
        
    }
    void setValue(float value) override;
    void enable(bool flag) override;

private:
    const std::string DEBUG_TEXT_PREFIX = "SOFTWARE_PIN ";
};


#endif //CMAKESFMLPROJECT_SOFTWAREPIN_H
