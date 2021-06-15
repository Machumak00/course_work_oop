#pragma once

#include "Behavior.h"

class BehaviorScorepoint : public Behavior {
public:
    void operator-(Player* player) override;
    BehaviorType get_type() override;
};
