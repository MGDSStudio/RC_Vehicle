//
// Created by gorod on 10.04.2026.
//

#include "BuzzerController.h"

#include "gpio/PinsInitializer.h"

void BuzzerController::init() {
    PinsInitializer pins_initializer;
    pins_initializer.getPins();

}


