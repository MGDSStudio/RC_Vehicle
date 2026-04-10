//
// Created by Alexander on 09.04.2026.
//

#include "MovementController.h"

#include "gpio/PinsInitializer.h"

MovementController::MovementController() {

    PinsInitializer pins_initializer;
    auto map = pins_initializer.getPins();

}
