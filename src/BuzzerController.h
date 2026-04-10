
//
// Created by gorod on 10.04.2026.
//

#ifndef CMAKESFMLPROJECT_BUZZERCONTROLLER_H
#define CMAKESFMLPROJECT_BUZZERCONTROLLER_H
#include "GlobalCommandsListener.h"
#include "IUpdateable.h"
#include "SinglePinActor.h"


class BuzzerController : public IUpdateable, GlobalCommandsListener{
    //


private:
    const std::filesystem::path PATH = Constants::PATH_TO_DATA / "gpio.json";

    void init();
    SinglePinActor single_pin_actor;
};


#endif //CMAKESFMLPROJECT_BUZZERCONTROLLER_H