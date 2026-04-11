//
// Created by Alexander on 09.04.2026.
//

#include "MovementController.h"

#include "GlobalCommandsListenersObserverSingleton.h"
#include "gpio/PinsInitializer.h"

MovementController::MovementController() {
    PinsInitializer pins_initializer;
    std::pmr::unordered_map<PinActionName, int> * map = pins_initializer.getPins();
    
    auto pinNumberLeftFrontForward = map->at(PinActionName::LEFT_FRONT_WHEEL_FORWARD);
    this->wheelForwardLeft.setPinForward(new SoftwarePin(pinNumberLeftFrontForward));
    auto pinNumberLeftFrontBackward = map->at(PinActionName::LEFT_FRONT_WHEEL_BACKWARD);
    this->wheelForwardLeft.setPinBackward(new SoftwarePin(pinNumberLeftFrontBackward));
    
    auto pinNumberRightFrontForward = map->at(PinActionName::RIGHT_FRONT_WHEEL_FORWARD);
    this->wheelForwardRight.setPinForward(new SoftwarePin(pinNumberRightFrontForward));
    auto pinNumberRightFrontBackward = map->at(PinActionName::RIGHT_FRONT_WHEEL_BACKWARD);
    this->wheelForwardRight.setPinBackward(new SoftwarePin(pinNumberRightFrontBackward));
    
    auto pinNumberLeftRearForward = map->at(PinActionName::LEFT_REAR_WHEEL_FORWARD);
    this->wheelBackwardLeft.setPinForward(new SoftwarePin(pinNumberLeftRearForward));
    auto pinNumberLeftRearBackward = map->at(PinActionName::LEFT_REAR_WHEEL_BACKWARD);
    this->wheelBackwardLeft.setPinBackward(new SoftwarePin(pinNumberLeftRearBackward));

    const auto pinNumberRightRearForward = map->at(PinActionName::RIGHT_REAR_WHEEL_FORWARD);
    this->wheelBackwardRight.setPinForward(new SoftwarePin(pinNumberRightRearForward));
    auto pinNumberRightRearBackward = map->at(PinActionName::RIGHT_REAR_WHEEL_BACKWARD);
    this->wheelBackwardRight.setPinBackward(new SoftwarePin(pinNumberRightRearBackward));

    GlobalCommandsListenersObserverSingleton::getInstance().subscribe(this);

    Logger::debug("Movement controller init successfully");
}

MovementController::~MovementController() {

}


void MovementController::update(float tpf){
    
}

void MovementController::complete() {
}

void MovementController::onCommandReceived(GlobalCommand &global_command) {
    //GlobalCommandsListener::onCommandReceived(global_command);
    if (global_command.getPrefix() == GlobalCommandPrefix::MOVEMENT){
        float value = global_command.getFloatValue();
        if (inDeadZone(value)) {
            Logger::debug("Stop movement");
        }
        else if (value > 0){
            //buzzer.enable(true);
            Logger::debug("Move forward");
        }
        else {
            //buzzer.enable(false);
            Logger::debug("Move backward");
        }
    }
    else if (global_command.getPrefix() == GlobalCommandPrefix::ROTATION) {
        float value = global_command.getFloatValue();
        if (inDeadZone(value)) {
            Logger::debug("Stop rotation");
        }
        else if (value > 0){
            //buzzer.enable(true);
            Logger::debug("Rotate cw");
        }
        else {
            //buzzer.enable(false);
            Logger::debug("rotate ccw");
        }
    }
    else {
        //auto val = global_command.getPrefix();
        Logger::debug("Wrong prefix for command" );
    }
}
