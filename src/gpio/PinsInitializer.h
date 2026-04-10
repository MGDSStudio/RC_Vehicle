//
// Created by gorod on 10.04.2026.
//

#ifndef CMAKESFMLPROJECT_PINSCREATOR_H
#define CMAKESFMLPROJECT_PINSCREATOR_H
#include <unordered_map>
#include <vector>

#include "PinActionNames.h"


class PinsCreator {

private:
    std::pmr::unordered_map<PinActionName, int> pins;
};


#endif //CMAKESFMLPROJECT_PINSCREATOR_H