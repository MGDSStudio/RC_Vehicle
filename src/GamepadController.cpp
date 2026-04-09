//
// Created by Alexander on 09.04.2026.
//

#include "GamepadController.h"
#include "Constants.h"
#include "Logger.h"


bool GamepadController::attachCommand(const std::optional<sf::Event> &event) {
    bool eventPickedUp = Constants::EVENT_CAN_NOT_ENCRYPTED;
    if (event->is<sf::Event::JoystickButtonPressed>()) {
        eventPickedUp = Constants::EVENT_PICKED_UP;
        eventsQueue.push(event);
    }
    else if (event->is<sf::Event::JoystickMoved>()) {
        eventPickedUp = Constants::EVENT_PICKED_UP;
        eventsQueue.push(event);
    }
    else if (event->is<sf::Event::JoystickConnected>()) {
        eventPickedUp = Constants::EVENT_PICKED_UP;
        eventsQueue.push(event);
    }
    else if (event->is<sf::Event::JoystickDisconnected>()) {
        eventPickedUp = Constants::EVENT_PICKED_UP;
        eventsQueue.push(event);
    }
    return eventPickedUp;
}

void GamepadController::update(float tpf) {
    if (!eventsQueue.empty()) {
        while (!eventsQueue.empty()) {
            auto event = eventsQueue.front();
            if (event->is<sf::Event::JoystickButtonPressed>()) {

            }
            else if (event->is<sf::Event::JoystickMoved>()) {

            }
            else if (event->is<sf::Event::JoystickConnected>()) {

            }
            else if (event->is<sf::Event::JoystickDisconnected>()) {

            }
            eventsQueue.pop();
            Logger::debug("Event received!");
        }
    }
}

void GamepadController::complete() {

}
