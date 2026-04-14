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
#include "../LocalCommandPrefix.h"
#include <SFML/Window.hpp>
#include <iostream>

#include "GamepadDataStruct.h"
#include "../GeometrieLibrary.h"
#include "../Constants.h"

#include "../LocalCommand.h"


class GamepadController final : public IUpdateable {
public:
    GamepadController();

    bool attachCommand(const std::optional<sf::Event> &event);
    void update(float tpf) override;
    void complete() override;

    void attachCompletionFlag(bool * window_must_be_redrawn) {
        this->completion_flag = window_must_be_redrawn;
    }

private:
    std::queue<std::optional<sf::Event>> sfLevelEventsQueue = {};
    GamepadDataStruct gamepadData;
    LocalCommandPrefix getPrefixForButton(unsigned int i);

    void attachButtonPressedData(const sf::Event::JoystickButtonPressed * button_pressed, LocalCommand * global_command);

    void attachButtonReleasedData(const sf::Event::JoystickButtonReleased * button_released, LocalCommand * global_command);

    LocalCommandPrefix getPrefixForAxis(sf::Joystick::Axis axis);

    void attachAxisMovedData(const sf::Event::JoystickMoved * joystick_moved, LocalCommand * global_command);

    void updateEventsQueue();
    void log(const std::string &text) const;
    const bool debug = false;
    bool* completion_flag = nullptr ;
};


#endif //CMAKESFMLPROJECT_GAMEPADCONTROLLER_H
