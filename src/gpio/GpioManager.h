//
// Created by Alexander on 11.04.2026.
//

#ifndef CMAKESFMLPROJECT_GPIOMANAGER_H
#define CMAKESFMLPROJECT_GPIOMANAGER_H


class GpioManager {
public:
    GpioManager();
    ~GpioManager();
    void complete();
private:
    bool initSuccessfully = true;
    bool completed = false;
};


#endif //CMAKESFMLPROJECT_GPIOMANAGER_H
