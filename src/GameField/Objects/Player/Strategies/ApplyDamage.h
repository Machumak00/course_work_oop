#pragma once

#include "ApplyElement.h"

class ApplyDamage : public ApplyElement {
public:
    void apply_element(const GameObject& damage, Player& player) const override;
};
