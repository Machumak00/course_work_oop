#pragma once

#include "Behavior.h"

class BehaviorTeleport : public Behavior {
public:
    void operator-(Player* player) override;
    BehaviorType get_type() override;
private:
    int power = 1;
};
