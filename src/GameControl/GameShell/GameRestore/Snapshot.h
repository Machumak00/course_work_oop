#pragma once
#include "FieldMemento.h"

class Snapshot {
public:
    Snapshot();
    Snapshot(std::vector<std::pair<int,int>> new_bomb_elements,
             std::vector<std::pair<int,int>> new_health_elements,
             std::vector<std::pair<int,int>> new_scorepoint_elements,
             std::vector<std::pair<int,int>> new_damage_enemies,
             std::vector<std::pair<int,int>> new_teleport_enemies,
             std::vector<std::pair<int,int>> new_scorepoint_enemies,
             std::pair<int, int> new_player_position,
             int new_player_scorepoint,
             int new_player_health);
    FieldMemento* get_memento() const;
    void restore();
private:
    FieldMemento* field_memento;
};
