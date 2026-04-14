//
// Created by gorod on 14.04.2026.
//

#ifndef CMAKESFMLPROJECT_STICKCONTROLLER_H
#define CMAKESFMLPROJECT_STICKCONTROLLER_H
#include "TouchPlace.h"


class StickController
{

public:
    void setX(const float x)
    {
        touch_place.setX(x);
        updateInDeadZone();
    }

    void setY(const float x)
    {
        touch_place.setX(x);
        updateInDeadZone();
    }


private:
    static constexpr float DEAD_ZONE_ANGLE = 25;
    TouchPlace touch_place;
    bool inDeadZone = true;

    void updateInDeadZone();
};


#endif //CMAKESFMLPROJECT_STICKCONTROLLER_H