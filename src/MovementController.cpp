//
// Created by Alexander on 09.04.2026.
//

#include "MovementController.h"
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

    auto pinNumberRightRearForward = map->at(PinActionName::RIGHT_REAR_WHEEL_FORWARD);
    this->wheelBackwardRight.setPinForward(new SoftwarePin(pinNumberLeftRearForward));
    auto pinNumberRightRearBackward = map->at(PinActionName::RIGHT_REAR_WHEEL_BACKWARD);
    this->wheelBackwardRight.setPinBackward(new SoftwarePin(pinNumberLeftRearBackward));
}

void MovementController::update(){
    
}