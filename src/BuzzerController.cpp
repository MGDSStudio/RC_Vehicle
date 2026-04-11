//
// Created by gorod on 10.04.2026.
//

#include "BuzzerController.h"


BuzzerController::BuzzerController(){
    init();
}

BuzzerController::~BuzzerController(){
    this->buzzer.complete();
}

void BuzzerController::init() {
    Logger::debug("Start to init buzzer-controller");
    PinsInitializer pins_initializer;
    std::pmr::unordered_map<PinActionName, int> *map = pins_initializer.getPins();
    auto buzzerPin = map->at(PinActionName::BUZZER);
    Logger::debug("buzzer pin at: " + std::to_string(buzzerPin) + " init successfully");
    this->buzzer.setPin(new SoftwarePin(buzzerPin));
    GlobalCommandsListenersObserverSingleton::getInstance().subscribe(this);
}

void BuzzerController::update(float tpf) {

}

void BuzzerController::onCommandReceived(GlobalCommand& global_command){
    if (global_command.getPrefix() == GlobalCommandPrefix::NOISE){
        bool enable = global_command.getBool();
        if (enable){
            buzzer.enable(true);
            Logger::debug("Buzzer enabled");
        }
        else {
            buzzer.enable(false);
            Logger::debug("Buzzer disabled");
        }
    }
}

void BuzzerController::complete(){
    buzzer.complete();
}

/*
failed with

[build] /home/mgdsstudio/Embedded/Programming/RC_Vehicle/RC_Vehicle/src/BuzzerController.cpp: In member function ‘void BuzzerController::init()’:
[build] /home/mgdsstudio/Embedded/Programming/RC_Vehicle/RC_Vehicle/src/BuzzerController.cpp:13:29: error: expected type-specifier before ‘SoftwarePin’
[build]    13 |     this->buzzer.setPin(new SoftwarePin(buzzerPin));*/