//
// Created by Alexander on 10.04.2026.
//

#include "GamepadDataStruct.h"

#include <fstream>
#include "GamepadInputNames.h"
#include "../Logger.h"
#include "magic_enum/magic_enum.hpp"

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

void GamepadDataStruct::init() {
    std::ifstream file(PATH);
    if (!file.is_open()) {
        Logger::criticalError("Can not load file under path: " + PATH.filename().string());
        return;
    }
    try {
        nlohmann::json data;
        file >> data;
        readButtonsData(data);
        Logger::debug("All the pins were read successfully");
    }
    catch (nlohmann::json::parse_error& e) {
        std::cerr << "Parsing error: " << e.what() << std::endl;
    }
}

GamepadDataStruct::GamepadDataStruct() {
    init();
}

void GamepadDataStruct::readButtonsData(nlohmann::json::const_reference json) {
    //int buzzerDigital = json[BUZZER_DIGITAL];

}

