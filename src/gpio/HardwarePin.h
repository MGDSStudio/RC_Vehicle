//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_HARDWAREPIN_H
#define CMAKESFMLPROJECT_HARDWAREPIN_H

#include "Pin.h"
#ifdef IS_RPI
    #include <pigpio.h>
#endif


class HardwarePin : public Pin{

};


#endif //CMAKESFMLPROJECT_HARDWAREPIN_H
