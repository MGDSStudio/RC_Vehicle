//
// Created by gorod on 09.04.2026.
//

#include "DebugLauncherBuzzerTest.h"
#include "Logger.h"
#include "SFML/System/Time.hpp"

void DebugLauncherBuzzerTest::update(float tpf) {
    sf::Time elapsed = clock.getElapsedTime(); // Получить текущее время
    /*
    if (elapsed.asSeconds() >= 4.0f) {
        if (statement == Statement::DISABLED) {
           // Logger::debug("Buzzer enabled");
            statement = Statement::ENABLED;
            GlobalCommand globalCommand(GlobalCommandPrefix::NOISE, true);
            GlobalCommandsListenersObserverSingleton::getInstance().broadcast(globalCommand);
        }
    }
    if (elapsed.asSeconds() >= 5.0f) {
        //Logger::debug("Buzzer disabled");
        clock.restart();
        statement = Statement::DISABLED;
        GlobalCommand globalCommand(GlobalCommandPrefix::NOISE, false);
        GlobalCommandsListenersObserverSingleton::getInstance().broadcast(globalCommand);
    }*/
}

void DebugLauncherBuzzerTest::complete() {
    
}
