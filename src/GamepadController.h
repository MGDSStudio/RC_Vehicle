//
// Created by Alexander on 09.04.2026.
//

#ifndef CMAKESFMLPROJECT_GAMEPADCONTROLLER_H
#define CMAKESFMLPROJECT_GAMEPADCONTROLLER_H
#include <optional>
#include <queue>
#include <SFML/Graphics.hpp>
#include "SFML/Window/Event.hpp"
#include "IUpdateable.h"

class GamepadController : public IUpdateable {
public:
    bool attachCommand(const std::optional<sf::Event> &event);
    void update(float tpf) override;
    void complete() override;
private:
    std::queue<std::optional<sf::Event>> eventsQueue = {};
    //std::vector<std::optional<sf::Event>> eventsQueue = {};
    //    std::vector<const std::optional<sf::Event>> eventsQueue = {};
};


#endif //CMAKESFMLPROJECT_GAMEPADCONTROLLER_H
