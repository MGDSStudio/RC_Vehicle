
//
// Created by gorod on 10.04.2026.
//

#ifndef CMAKESFMLPROJECT_BUZZERCONTROLLER_H
#define CMAKESFMLPROJECT_BUZZERCONTROLLER_H
#include "GlobalCommandsListener.h"
#include "IUpdateable.h"
#include "SinglePinActor.h"
#include "gpio/SoftwarePin.h"
#include "gpio/PinsInitializer.h"
#include "GlobalCommandPrefix.h"
#include "GlobalCommandsListenersObserverSingleton.h"

class BuzzerController : public IUpdateable, GlobalCommandsListener{
    //

public:

    BuzzerController();
    ~BuzzerController();

    void update(float tpf) override;
    void complete() override;
    void onCommandReceived(GlobalCommand& global_command) override;
    
private:
    const std::filesystem::path PATH = Constants::PATH_TO_DATA / "gpio.json";

    void init();
    SinglePinActor buzzer;
};


#endif //CMAKESFMLPROJECT_BUZZERCONTROLLER_H