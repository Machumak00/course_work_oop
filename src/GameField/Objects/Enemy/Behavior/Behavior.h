#pragma once
#include <iostream>

class Player;
class Behavior {
public:
    enum BehaviorType {Damage, Teleport, Scorepoint};
    virtual void operator-(Player* player) = 0;
    virtual BehaviorType get_type() = 0;
};
