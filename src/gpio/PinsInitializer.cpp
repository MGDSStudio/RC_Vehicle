//
// Created by gorod on 10.04.2026.
//

#include "PinsInitializer.h"

#include <iosfwd>
#include <iostream>

std::pmr::unordered_map<PinActionName, int> * PinsInitializer::getPins() {
    if (!initialized) init();
    return &pins;
}

void PinsInitializer::init() {
    std::ifstream file(PATH);
    if (!file.is_open()) {
        std::cerr << "Can not load file!" << std::endl;
        return;
    }

    try {
        json data;
        file >> data;
        int number;
        constexpr auto pinActionNames = magic_enum::enum_names<PinActionName>();
        //std::string name = data["name"];
        int version = data["LEFT_FRONT_WHEEL_FORWARD"];
        std::cout << "Name: " << "LEFT_FRONT_WHEEL_FORWARD" << ", number: " << version << std::endl;

    } catch (json::parse_error& e) {
        std::cerr << "Parsing error: " << e.what() << std::endl;
    }

    initialized = true;
}
