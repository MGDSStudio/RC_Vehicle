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
using json = nlohmann::json;

#include "PinActionName.h"
#include "../Constants.h"
#include "magic_enum/magic_enum.hpp"

class PinsInitializer {

public:
    std::pmr::unordered_map<PinActionName, int>* getPins();

private:
    const std::filesystem::path PATH = Constants::PATH_TO_DATA / "gpio.json";
    void init();
    std::pmr::unordered_map<PinActionName, int> pins;
    bool initialized = false;
};


#endif //CMAKESFMLPROJECT_PINSCREATOR_H