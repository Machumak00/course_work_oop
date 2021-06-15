#pragma once

#include "Player.h"

class ApplyElement;
class ApplyToPlayer {
public:
    explicit ApplyToPlayer(ApplyElement* new_apply_element = nullptr);
    ~ApplyToPlayer();
    void set_strategy(ApplyElement* new_apply_element);
    void choose_strategy(GameObject::ObjectType obj);
    void apply_element_to_player(const GameObject& object, Player& player) const;
private:
    ApplyElement* apply_element;
};
