//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_GAMEPADCONTROLLER_H
#define CMAKESFMLPROJECT_GAMEPADCONTROLLER_H
#include <optional>
#include <queue>
#include <SFML/Graphics.hpp>
#include "SFML/Window/Event.hpp"
#include "../IUpdateable.h"
#include "../GlobalCommandPrefix.h"
#include <SFML/Window.hpp>
#include <iostream>

#include "GamepadDataStruct.h"
#include "../GeometrieLibrary.h"
#include "../Constants.h"

#include "../GlobalCommand.h"


class GamepadController final : public IUpdateable {
public:
    GamepadController();

    bool attachCommand(const std::optional<sf::Event> &event);
    void update(float tpf) override;
    void complete() override;
private:
    std::queue<std::optional<sf::Event>> sfLevelEventsQueue = {};
    GamepadDataStruct gamepadData;
    GlobalCommandPrefix getPrefixForButton(unsigned int i) const;

    void attachButtonPressedData(const sf::Event::JoystickButtonPressed * button_pressed, GlobalCommand * global_command) const;

    void attachButtonReleasedData(const sf::Event::JoystickButtonReleased * button_released, GlobalCommand * global_command) const;

    GlobalCommandPrefix getPrefixForAxis(sf::Joystick::Axis axis);

    void attachAxisMovedData(const sf::Event::JoystickMoved * joystick_moved, GlobalCommand * global_command);

    void updateEventsQueue();
    void log(const std::string &text) const;
    const bool debug = false;
};


#endif //CMAKESFMLPROJECT_GAMEPADCONTROLLER_H
