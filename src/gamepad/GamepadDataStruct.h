//
// Created by Alexander on 10.04.2026.
//

#ifndef CMAKESFMLPROJECT_GAMEPADDATASTRUCT_H
#define CMAKESFMLPROJECT_GAMEPADDATASTRUCT_H


#include <string>
#include <unordered_map>

class GamepadDataStruct {
private:
    std::unordered_map <std::string, int> buttonsMap;
    std::unordered_map <std::string, int> axesMap;
};


#endif //CMAKESFMLPROJECT_GAMEPADDATASTRUCT_H
