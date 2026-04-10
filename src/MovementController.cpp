//
// Created by Alexander on 09.04.2026.
//

#include "MovementController.h"
#include "gpio/PinsInitializer.h"

MovementController::MovementController() {
    PinsInitializer pins_initializer;
    std::pmr::unordered_map<PinActionName, int> * map = pins_initializer.getPins();
    
    auto pinNumberLeftFrontForward = map->at(PinActionName::LEFT_FRONT_WHEEL_FORWARD);
    this->wheelForwardLeft.setPinForward(&(SoftwarePin(pinNumberLeftFrontForward)));
    auto pinNumberLeftFrontBackward = map->at(PinActionName::LEFT_FRONT_WHEEL_BACKWARD);
    this->wheelForwardLeft.setPinBackward(&(SoftwarePin(pinNumberLeftFrontBackward)));
    
    auto pinNumberRightFrontForward = map->at(PinActionName::RIGHT_FRONT_WHEEL_FORWARD);
    this->wheelForwardRight.setPinForward(&(SoftwarePin(pinNumberRightFrontForward)));
    auto pinNumberRightFrontBackward = map->at(PinActionName::RIGHT_FRONT_WHEEL_BACKWARD);
    this->wheelForwardRight.setPinBackward(&(SoftwarePin(pinNumberRightFrontBackward)));
    
    auto pinNumberLeftRearForward = map->at(PinActionName::LEFT_REAR_WHEEL_FORWARD);
    this->wheelBackwardLeft.setPinForward(&(SoftwarePin(pinNumberLeftRearForward)));
    auto pinNumberLeftRearBackward = map->at(PinActionName::LEFT_REAR_WHEEL_BACKWARD);
    this->wheelBackwardLeft.setPinBackward(&(SoftwarePin(pinNumberLeftRearBackward)));

    auto pinNumberRightRearForward = map->at(PinActionName::RIGHT_REAR_WHEEL_FORWARD);
    this->wheelBackwardRight.setPinForward(&(SoftwarePin(pinNumberLeftRearForward)));
    auto pinNumberRightRearBackward = map->at(PinActionName::RIGHT_REAR_WHEEL_BACKWARD);
    this->wheelBackwardRight.setPinBackward(&(SoftwarePin(pinNumberLeftRearBackward)));
}

void MovementController::update(){
    
}

/*
    SinglePinActor* wheelForwardLeft;
    SinglePinActor* wheelForwardRight;
    SinglePinActor* wheelBackwardLeft;
    SinglePinActor* wheelBackwardRight;
    */