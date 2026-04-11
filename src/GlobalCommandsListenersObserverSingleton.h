//
// Created by gorod on 10.04.2026.
//

#ifndef CMAKESFMLPROJECT_GLOBALCOMMANDSLISTENERSOBSERVERSINGLETON_H
#define CMAKESFMLPROJECT_GLOBALCOMMANDSLISTENERSOBSERVERSINGLETON_H
#include <vector>

#include "GlobalCommandsListener.h"


class GlobalCommandsListenersObserverSingleton {

public:
    GlobalCommandsListenersObserverSingleton(const GlobalCommandsListenersObserverSingleton &) = delete;
    void operator=(const GlobalCommandsListenersObserverSingleton &) = delete;

    static GlobalCommandsListenersObserverSingleton& getInstance() {
        static GlobalCommandsListenersObserverSingleton instance;
        return instance;
    }
    void subscribe(GlobalCommandsListener* listener);
    void unsubscribe(GlobalCommandsListener* listener);
    void broadcast(GlobalCommand &global_command) const;

private:
    GlobalCommandsListenersObserverSingleton();
    std::vector<GlobalCommandsListener*> listeners;
};


#endif //CMAKESFMLPROJECT_GLOBALCOMMANDSLISTENERSOBSERVERSINGLETON_H