//
// Created by gorod on 10.04.2026.
//

#include "GlobalCommandsListenersObserverSingleton.h"

GlobalCommandsListenersObserverSingleton::GlobalCommandsListenersObserverSingleton(){
    
}

void GlobalCommandsListenersObserverSingleton::complete() {
    listeners.clear();
}

void GlobalCommandsListenersObserverSingleton::subscribe(GlobalCommandsListener* listener) {
    listeners.push_back(listener);
}

void GlobalCommandsListenersObserverSingleton::unsubscribe(GlobalCommandsListener* listener) {
    auto it = std::find(listeners.begin(), listeners.end(), listener);
    if (it != listeners.end()){
        //found
        listeners.erase(it);
    }
    else{
        //not found
    }
}

void GlobalCommandsListenersObserverSingleton::broadcast(GlobalCommand &global_command) const {
    for (const auto listener : listeners) {
        listener->onCommandReceived(global_command);
    }
}
