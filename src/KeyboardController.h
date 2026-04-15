//
// Created by gorod on 15.04.2026.
//

#ifndef CMAKESFMLPROJECT_KEYBOARDCONTROLLER_H
#define CMAKESFMLPROJECT_KEYBOARDCONTROLLER_H

#include "IUpdateable.h"
#include <optional>
#include "LocalCommand.h"
#include "SFML/Window/Event.hpp"

class KeyboardController final : public IUpdateable
{
    public:
    KeyboardController();
    ~KeyboardController() override;
    bool attachCommand(const std::optional<sf::Event> &event);
    void update(float tpf) override;
    void complete() override;

private:
    void attachButtonPressedData(const sf::Event::KeyPressed *button_pressed, LocalCommand *global_command);

};


#endif //CMAKESFMLPROJECT_KEYBOARDCONTROLLER_H