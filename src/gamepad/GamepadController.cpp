//
// Created by Alexander on 09.04.2026.
//

#include "GamepadController.h"
#include "../Constants.h"
#include "../Logger.h"
#include "../GlobalCommand.h"


GamepadController::GamepadController(){
    bool connected = sf::Joystick::isConnected(0);
    std::string text = "gamepdad ";
    if (connected) text+=" connected successfully";
    else text+= "can not connected";
    Logger::debug(text);
}

bool GamepadController::attachCommand(const std::optional<sf::Event> &event) {
    bool eventPickedUp = Constants::EVENT_CAN_NOT_ENCRYPTED;
    if (event->is<sf::Event::JoystickButtonPressed>()) {
        eventPickedUp = Constants::EVENT_PICKED_UP;
        Logger::debug("Some command received pressed");
        eventsQueue.push(event);
    }
    else if (event->is<sf::Event::JoystickMoved>()) {
        Logger::debug("Some command received moved");
        eventPickedUp = Constants::EVENT_PICKED_UP;
        eventsQueue.push(event);
    }
    else if (event->is<sf::Event::JoystickConnected>()) {
        Logger::debug("Some command received connected");
        eventPickedUp = Constants::EVENT_PICKED_UP;
        eventsQueue.push(event);
    }
    else if (event->is<sf::Event::JoystickDisconnected>()) {
        Logger::debug("Some command received disconected");
        eventPickedUp = Constants::EVENT_PICKED_UP;
        eventsQueue.push(event);
    }
    //
    return eventPickedUp;
}

void GamepadController::update(float tpf) {
    if (!eventsQueue.empty()) {
        while (!eventsQueue.empty()) {
            GlobalCommand globalCommand;
            auto event = eventsQueue.front();
            if (const auto* buttonPressed = event->getIf<sf::Event::JoystickButtonPressed>()) {
                unsigned int button = buttonPressed->button;
                //unsigned int id = buttonPressed->joystickId;
                GlobalCommandPrefix globalCommandPrefix = getPrefixForButton(button);
                //globalCommand.setIntValue((int)button);
                globalCommand.setPrefix(globalCommandPrefix);
                globalCommand.setFloatValue(Constants::MAX_ANALOG_VALUE);
                Logger::debug("Gamepad button pressed");
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

GlobalCommandPrefix GamepadController::getPrefixForButton(unsigned int buttonCode) {
    return GlobalCommandPrefix::RIGHT;
}
