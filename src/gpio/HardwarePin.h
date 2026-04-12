//
// Created by Alexander on 11.04.2026.
//

#ifndef CMAKESFMLPROJECT_PINABSTRACT_H
#define CMAKESFMLPROJECT_PINABSTRACT_H

#include <string>

class HardwarePin {
public:
    HardwarePin(int number){
        this->hardwareNumber = number;
        this->numberAsString = std::to_string(number);
    }
    virtual ~HardwarePin() = default;
    virtual void setValue(float value) = 0;
    virtual void enable(bool flag) = 0;
    virtual void complete() = 0;

protected:
    int hardwareNumber;
    std::string name;
    std::string numberAsString;
};



#endif //CMAKESFMLPROJECT_PINABSTRACT_H
