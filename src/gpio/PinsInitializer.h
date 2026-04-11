//
// Created by gorod on 10.04.2026.
//

#ifndef CMAKESFMLPROJECT_PINSCREATOR_H
#define CMAKESFMLPROJECT_PINSCREATOR_H
#include <unordered_map>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <filesystem>

#include "PinActionName.h"
#include "../Constants.h"
#include "magic_enum/magic_enum.hpp"
#include "../Logger.h"

class PinsInitializer {

public:
    std::pmr::unordered_map<PinActionName, int>* getPins();

private:
    void init();
    void addInMap(std::string name, nlohmann::json* data);

    const std::filesystem::path PATH = Constants::PATH_TO_DATA / "gpio.json";
    inline static std::pmr::unordered_map<PinActionName, int> pins;
    static bool initialized;
};


#endif //CMAKESFMLPROJECT_PINSCREATOR_H