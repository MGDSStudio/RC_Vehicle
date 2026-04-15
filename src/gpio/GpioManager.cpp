//
// Created by Alexander on 11.04.2026.
//

#include "GpioManager.h"
#ifdef IS_RPI
    #include <pigpio.h>
#endif

GpioManager::GpioManager() {
#ifdef IS_RPI
    if (gpioInitialise()<0){
        Logger::debug("Can not init GPIO");
        initSuccessfully = false;
        System.exit(1);
    }
    else {
        Logger::debug("GPIO was init successfully");
    }
#endif
}

GpioManager::~GpioManager() {
    complete();
}

void GpioManager::complete() {
    if (!completed){
        completed = true;
#ifdef IS_RPI
        if (initSuccessfully){
        gpioTerminate();
    }
#endif
    }

}