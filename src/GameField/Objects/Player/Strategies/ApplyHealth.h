#pragma once

#include "ApplyElement.h"

class ApplyHealth : public ApplyElement {
public:
    void apply_element(const GameObject& health, Player& player) const override;
};
