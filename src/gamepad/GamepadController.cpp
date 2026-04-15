//
// Created by Alexander on 09.04.2026.
//

#include "GamepadController.h"
#include "../Constants.h"
#include "../Logger.h"
#include "../LocalCommand.h"
#include <magic_enum/magic_enum.hpp>

#include "../LocalCommandsListenersObserverSingleton.h"


GamepadController::GamepadController(){
    const bool connected = sf::Joystick::isConnected(0);
    std::string text = "Gamepad ";
    if (connected) {
        const auto identificationStruct = sf::Joystick::Identification();
        const auto name =  identificationStruct.name;
        const auto id = std::to_string(identificationStruct.productId);
        text+=(name + ", ID: ");
        text+=id;
        text+=(" connected successfully");
    }
    else {
        text+= " not found";
    }
    Logger::debug(text);
}

GamepadController::~GamepadController()
{

}

bool GamepadController::attachCommand(const std::optional<sf::Event> &event) {
    bool eventPickedUp = Constants::EVENT_CAN_NOT_ENCRYPTED;
    if (event->is<sf::Event::JoystickButtonPressed>()) {
        eventPickedUp = Constants::EVENT_PICKED_UP;
        sfLevelEventsQueue.push(event);
    }
    if (event->is<sf::Event::JoystickButtonReleased>()) {
        eventPickedUp = Constants::EVENT_PICKED_UP;
        sfLevelEventsQueue.push(event);
    } else if (event->is<sf::Event::JoystickMoved>()) {
        eventPickedUp = Constants::EVENT_PICKED_UP;
        sfLevelEventsQueue.push(event);
    }
    else if (event->is<sf::Event::JoystickConnected>()) {
        eventPickedUp = Constants::EVENT_PICKED_UP;
        sfLevelEventsQueue.push(event);
    }
    else if (event->is<sf::Event::JoystickDisconnected>()) {
        eventPickedUp = Constants::EVENT_PICKED_UP;
        sfLevelEventsQueue.push(event);
    }
    if (!sfLevelEventsQueue.empty()){
        updateEventsQueue();
    }
    return eventPickedUp;
}

void GamepadController::update(float tpf) {
}

void GamepadController::complete() {
    
}

void GamepadController::updateEventsQueue()
{
    while (!sfLevelEventsQueue.empty()) {
            LocalCommand globalCommand;
            auto event = sfLevelEventsQueue.front();
            if (const auto* button_pressed = event->getIf<sf::Event::JoystickButtonPressed>()) {
                attachButtonPressedData(button_pressed, &globalCommand);
            }
            else if (const auto* button_released = event->getIf<sf::Event::JoystickButtonReleased>()) {
                attachButtonReleasedData(button_released, &globalCommand);
            }
            else if (event->is<sf::Event::JoystickMoved>()) {
                const auto* axisMoved = event->getIf<sf::Event::JoystickMoved>();
                attachAxisMovedData(axisMoved, &globalCommand);
            }
            else if (event->is<sf::Event::JoystickConnected>()) {
                const auto* joystick_connected = event->getIf<sf::Event::JoystickConnected>();
                const auto id = joystick_connected->joystickId;
                log("Game pad ID: " + std::to_string(id) + " is connected");
            }
            else if (event->is<sf::Event::JoystickDisconnected>()) {
                const auto* joystick_disconnected = event->getIf<sf::Event::JoystickDisconnected>();
                const auto id = joystick_disconnected->joystickId;
                log("Game pad ID: " + std::to_string(id) + " is disconnected");
            }

            if (globalCommand.getPrefix() != LocalCommandPrefix::NO_DATA) {
                LocalCommandsListenersObserverSingleton::getInstance().broadcast(globalCommand);
            }
            sfLevelEventsQueue.pop();
        }
}

void GamepadController::attachAxisMovedData(const sf::Event::JoystickMoved *joystick_moved, LocalCommand *global_command) {
    const auto axis = joystick_moved->axis;
    global_command->setPrefix(getPrefixForAxis(axis));
    const float value = GeometrieLibrary::map(joystick_moved->position, Constants::MIN_GAMEPAD_AXIS_VALUE, Constants::MAX_GAMEPAD_AXIS_VALUE,  Constants::MIN_ANALOG_VALUE, Constants::MAX_ANALOG_VALUE);
    global_command->setFloatValue(value);
    if (debug) {
        const auto stringView = magic_enum::enum_name(axis);
        const std::string name_str(stringView);
        log("Axis: " + name_str + " value: " + std::to_string(value));
    }
}

void GamepadController::attachButtonPressedData(const sf::Event::JoystickButtonPressed *button_pressed, LocalCommand *global_command) {
    unsigned int button = button_pressed->button;
    global_command->setPrefix(getPrefixForButton(button));
    global_command->setFloatValue(Constants::MAX_ANALOG_VALUE);
    global_command->setBoolValue(true);
    if (debug) {
        const auto stringView = magic_enum::enum_name(global_command->getPrefix());
        const std::string name_str(stringView);
        log("Button: " + std::to_string(button) + " pressed and command " + name_str + " generated");
    }
}

void GamepadController::attachButtonReleasedData(const sf::Event::JoystickButtonReleased *button_released,    LocalCommand *global_command){
    const unsigned int button = button_released->button;
    auto prefix = getPrefixForButton(button);
    if (prefix == LocalCommandPrefix::SWITCH_OFF)
    {
        *this->completion_flag = true;
    }
    else
    {
        global_command->setFloatValue(Constants::MIN_ANALOG_VALUE);
        global_command->setBoolValue(false);
        if (debug) {
            const auto stringView = magic_enum::enum_name(global_command->getPrefix());
            const std::string name_str(stringView);
            log("Button: " + std::to_string(button) + " released for command " + name_str);
        }
    }
    global_command->setPrefix(prefix);
}

LocalCommandPrefix GamepadController::getPrefixForAxis(const sf::Joystick::Axis axis) {
    const std::string name = gamepadData.getNameForAxis(axis);
    auto global_command_prefix = LocalCommandPrefix::NO_DATA;
    if (name != NO_DATA) {
        if (name == BUZZER_ANALOG) {
            global_command_prefix = LocalCommandPrefix::NOISE_ANALOG;
        }
        else if (name == ROTATION_ANALOG) {
            global_command_prefix = LocalCommandPrefix::ROTATION;
        }
        else if (name == MOVEMENT_ANALOG) {
            global_command_prefix = LocalCommandPrefix::MOVEMENT;
        }
    }
    return global_command_prefix;
}

LocalCommandPrefix GamepadController::getPrefixForButton(unsigned int buttonCode) {
    const std::string name = gamepadData.getNameForButton(buttonCode);
    auto global_command_prefix = LocalCommandPrefix::NO_DATA;
    if (name != NO_DATA) {
        if (name == BUZZER_DIGITAL) {
            global_command_prefix = LocalCommandPrefix::NOISE_DIGITAL;
        }
        else if (name == SWITCH_OFF) {
            global_command_prefix = LocalCommandPrefix::SWITCH_OFF;
            *this->completion_flag = true;
        }
        else if (name == PAUSE) {
            global_command_prefix = LocalCommandPrefix::PAUSE;
            //*this->completion_flag = true;
        }
    }
    return global_command_prefix;
}

void GamepadController::log(const std::string &text) const{
    if (debug){
        Logger::debug("Gamepad: " + text);
    }
}


/*
void GamepadController::updateEventsQueue()
{
    while (!sfLevelEventsQueue.empty()) {
            GlobalCommand* globalCommand = new GlobalCommand();
            auto event = sfLevelEventsQueue.front();
            if (const auto* button_pressed = event->getIf<sf::Event::JoystickButtonPressed>()) {
                attachButtonPressedData(button_pressed, globalCommand);
            }
            else if (const auto* button_released = event->getIf<sf::Event::JoystickButtonReleased>()) {
                attachButtonReleasedData(button_released, globalCommand);
            }
            else if (event->is<sf::Event::JoystickMoved>()) {
                const auto* axisMoved = event->getIf<sf::Event::JoystickMoved>();
                attachAxisMovedData(axisMoved, globalCommand);
            }
            else if (event->is<sf::Event::JoystickConnected>()) {
                const auto* joystick_connected = event->getIf<sf::Event::JoystickConnected>();
                const auto id = joystick_connected->joystickId;
                log("Game pad ID: " + std::to_string(id) + " is connected");
            }
            else if (event->is<sf::Event::JoystickDisconnected>()) {
                const auto* joystick_disconnected = event->getIf<sf::Event::JoystickDisconnected>();
                const auto id = joystick_disconnected->joystickId;
                log("Game pad ID: " + std::to_string(id) + " is disconnected");
            }
            if (globalCommand.getPrefix() != GlobalCommandPrefix::NO_DATA) {
                GlobalCommandsListenersObserverSingleton::getInstance().broadcast(globalCommand);
            }
            delete globalCommand;
            sfLevelEventsQueue.pop();
        }
}
*/