//
// Created by Alexander on 10.04.2026.
//

#ifndef CMAKESFMLPROJECT_GAMEPADDATASTRUCT_H
#define CMAKESFMLPROJECT_GAMEPADDATASTRUCT_H


#include <filesystem>
#include <string>
#include <unordered_map>
#include "../Constants.h"
#include <filesystem>
#include <nlohmann/json.hpp>
#include "InputKeys.h"
#include "SFML/Window/Joystick.hpp"
#include "GamepadInputNames.h"

class GamepadDataStruct {

public:
    GamepadDataStruct();

    std::string getNameForButton(unsigned int button_code) const {
        if (button_code == buzzerButton) return BUZZER_DIGITAL;
        else if (button_code == gripperPressButton) return GRIPPER_PRESS;
        else if (button_code == gripperReleaseButton) return GRIPPER_RELEASE;
        else if (button_code == gripperUpButton) return GRIPPER_UP;
        else if (button_code == gripperDownButton) return GRIPPER_DOWN;
        else if (button_code == switch_off) return SWITCH_OFF;
        else {
            return NO_DATA;
        }
    }

    std::string getNameForAxis(sf::Joystick::Axis axis) {
        if (axis == xAxis || axis == xAxisDigital) return ROTATION_ANALOG;
        else if (axis == yAxis || axis == yAxisDigital) return MOVEMENT_ANALOG;
        else if (axis == buzzerAxis) return BUZZER_ANALOG;
        else return NO_DATA;
    }

private:
    const std::filesystem::path PATH = Constants::PATH_TO_DATA / "gamepad.json";
    std::unordered_map <std::string, int> buttonsMap;
    std::unordered_map <std::string, int> axesMap;

    void readButtonsData(nlohmann::json::const_reference json);

    void init();

    int buzzerButton = 0;
    int gripperPressButton = -1;
    int gripperReleaseButton = -1;
    int gripperUpButton = -1;
    int gripperDownButton = -1;
    int switch_off = -1;
    sf::Joystick::Axis xAxis = sf::Joystick::Axis::X;
    sf::Joystick::Axis yAxis = sf::Joystick::Axis::Y;
    sf::Joystick::Axis xAxisDigital = sf::Joystick::Axis::PovX;
    sf::Joystick::Axis yAxisDigital = sf::Joystick::Axis::PovY;
    sf::Joystick::Axis buzzerAxis = sf::Joystick::Axis::R;
};


#endif //CMAKESFMLPROJECT_GAMEPADDATASTRUCT_H


/*
"BUZZER_DIGITAL": 0,
  "GRIPPER_PRESS": 4,
  "GRIPPER_RELEASE": 5,
  "GRIPPER_UP": 2,
  "GRIPPER_DOWN": 3,
  "MOVE_FORWARD_DIGITAL": -1,
  "MOVE_BACKWARD_DIGITAL": -1,
  "ROTATE_CW_DIGITAL": -1,
  "ROTATE_CCW_DIGITAL": -1,
  "MOVEMENT_DIGITAL": "PovY",
  "ROTATION_DIGITAL": "PovX",
  "MOVEMENT_ANALOG": "X",
  "ROTATION_ANALOG": "Y",
  "BUZZER_ANALOG": "Z"
 */