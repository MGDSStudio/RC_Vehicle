//
// Created by gorod on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_DEBUGLAUNCHER1_H
#define CMAKESFMLPROJECT_DEBUGLAUNCHER1_H
#include "IUpdateable.h"
#include "SFML/System/Clock.hpp"
#include "GlobalCommand.h"
#include "GlobalCommandsListenersObserverSingleton.h"

enum class Statement {
    DISABLED, ENABLED
};

class DebugLauncherBuzzerTest : public IUpdateable {

public:
    void update(float tpf) override;
    void complete() override;

private:
    sf::Clock clock;
    Statement statement = Statement::DISABLED;
};


#endif //CMAKESFMLPROJECT_DEBUGLAUNCHER1_H