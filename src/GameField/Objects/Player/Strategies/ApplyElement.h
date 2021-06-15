#pragma once

#include "GameObject.h"
#include "Player.h"

class ApplyElement {
public:
    virtual ~ApplyElement() = default;
    virtual void apply_element(const GameObject& obj, Player& player) const = 0;
};