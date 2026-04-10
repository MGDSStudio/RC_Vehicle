//
// Created by gorod on 10.04.2026.
//

#ifndef CMAKESFMLPROJECT_GLOBALCOMMANDSLISTENER_H
#define CMAKESFMLPROJECT_GLOBALCOMMANDSLISTENER_H
#include "GlobalCommand.h"


class GlobalCommandsListener {
public:
    virtual void onCommandReceived(GlobalCommand& global_command);
};


#endif //CMAKESFMLPROJECT_GLOBALCOMMANDSLISTENER_H