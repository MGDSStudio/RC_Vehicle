//
// Created by gorod on 10.04.2026.
//

#include "GlobalCommandsListenersObserverSingleton.h"

GlobalCommandsListenersObserverSingleton::GlobalCommandsListenersObserverSingleton(){
    
}

void GlobalCommandsListenersObserverSingleton::subscribe(GlobalCommandsListener* listener) {
    listeners.push_back(listener);
}

void GlobalCommandsListenersObserverSingleton::unsubscribe(GlobalCommandsListener* listener) {
    //if (listeners.)
}

void GlobalCommandsListenersObserverSingleton::broadcast(GlobalCommand &global_command) const {
    for (auto listener : listeners) {
        listener->onCommandReceived(global_command);
    }
}
