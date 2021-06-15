#pragma once
#include "libraries.h"

class GameSettings;
class FieldMemento {
public:
    FieldMemento() = default;
    FieldMemento(std::vector<std::pair<int,int>> new_bomb_elements,
                 std::vector<std::pair<int,int>> new_health_elements,
                 std::vector<std::pair<int,int>> new_scorepoint_elements,
                 std::vector<std::pair<int,int>> new_damage_enemies,
                 std::vector<std::pair<int,int>> new_teleport_enemies,
                 std::vector<std::pair<int,int>> new_scorepoint_enemies,
                 std::pair<int, int> new_player_position,
                 int new_player_scorepoint,
                 int new_player_health);
    //геттеры
    std::vector<std::pair<int,int>> get_bomb_elements() const;
    std::vector<std::pair<int,int>> get_health_elements() const;
    std::vector<std::pair<int,int>> get_scorepoint_elements() const;
    std::vector<std::pair<int,int>> get_teleport_enemies() const;
    std::vector<std::pair<int,int>> get_damage_enemies() const;
    std::vector<std::pair<int,int>> get_scorepoint_enemies() const;
    std::pair<int, int> get_player_position() const;
    int get_player_scorepoint() const;
    int get_player_health() const;
    //сеттеры
    void set_bomb_element(std::pair<int,int> new_bomb_element);
    void set_health_elements(std::pair<int,int> new_health_element);
    void set_scorepoint_elements(std::pair<int,int> new_scorepoint_element);
    void set_teleport_enemies(std::pair<int,int> new_teleport_enemy);
    void set_damage_enemies(std::pair<int,int> new_damage_enemy);
    void set_scorepoint_enemies(std::pair<int,int> new_scorepoint_enemy);
    void set_player_position(std::pair<int, int> new_player_position);
    void set_player_scorepoint(int new_player_scorepoint);
    void set_player_health(int new_player_health);
private:
    std::vector<std::pair<int,int>> bomb_elements;
    std::vector<std::pair<int,int>> health_elements;
    std::vector<std::pair<int,int>> scorepoint_elements;
    std::vector<std::pair<int,int>> damage_enemies;
    std::vector<std::pair<int,int>> teleport_enemies;
    std::vector<std::pair<int,int>> scorepoint_enemies;
    std::pair<int, int> player_position;
    int player_scorepoint;
    int player_health;
};
