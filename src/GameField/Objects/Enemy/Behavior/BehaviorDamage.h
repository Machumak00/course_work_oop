#pragma once

#include "Behavior.h"

class BehaviorDamage : public Behavior {
public:
    void operator-(Player* player) override;
    BehaviorType get_type() override;
};
