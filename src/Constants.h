//
// Created by gorod on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_CONSTANTS_H
#define CMAKESFMLPROJECT_CONSTANTS_H
#include <string>

//static constexpr bool EVENT_PICKED_UP = true;

class Constants {
public:
    static constexpr bool EVENT_PICKED_UP = true;
    static constexpr bool EVENT_CAN_NOT_ENCRYPTED = !EVENT_PICKED_UP;
    static constexpr float MAX_ANALOG_VALUE = 1;
    static constexpr float MIN_ANALOG_VALUE = -1;


};


#endif //CMAKESFMLPROJECT_CONSTANTS_H