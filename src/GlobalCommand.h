//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_GLOBALCOMMAND_H
#define CMAKESFMLPROJECT_GLOBALCOMMAND_H

enum class Prefix{
    FORWARD, BACKWARD, LEFT, RIGHT, NOISE
};
class GlobalCommand {

public:
    Prefix getPrefix() const;

    float getValue() const;

private:
    Prefix prefix;
    float value;
};


#endif //CMAKESFMLPROJECT_GLOBALCOMMAND_H
