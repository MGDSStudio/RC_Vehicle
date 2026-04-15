//
// Created by gorod on 15.04.2026.
//

#include "KeyboardController.h"






namespace sf
{
    class Event;
}

KeyboardController::KeyboardController()
{
}

KeyboardController::~KeyboardController()
{
}

void KeyboardController::update(float tpf)
{

}

void KeyboardController::complete()
{

}

bool KeyboardController::attachCommand(const std::optional<sf::Event> &event)
{

    bool pickedUp = true;
    if (const auto* button_pressed = event->getIf<sf::Event::KeyPressed>()) {
        LocalCommand globalCommand;
        attachButtonPressedData(button_pressed, &globalCommand);
    }
    else if (const auto* button_released = event->getIf<sf::Event::KeyReleased>()) {
        LocalCommand globalCommand;
        //attachButtonReleasedData(button_released, &globalCommand);
    }
    else pickedUp = false;
    return pickedUp;
}

void KeyboardController::attachButtonPressedData(const sf::Event::KeyPressed *button_pressed, LocalCommand *global_command) {
    /*unsigned int button = button_pressed->button;
    global_command->setPrefix(getPrefixForButton(button));
    global_command->setFloatValue(Constants::MAX_ANALOG_VALUE);
    global_command->setBoolValue(true);
    if (debug) {
        const auto stringView = magic_enum::enum_name(global_command->getPrefix());
        const std::string name_str(stringView);
        log("Button: " + std::to_string(button) + " pressed and command " + name_str + " generated");
    }*/
}
