#include "FieldMemento.h"

FieldMemento::FieldMemento(std::vector<std::pair<int,int>> new_bomb_elements,
                           std::vector<std::pair<int,int>> new_health_elements,
                           std::vector<std::pair<int,int>> new_scorepoint_elements,
                           std::vector<std::pair<int,int>> new_damage_enemies,
                           std::vector<std::pair<int,int>> new_teleport_enemies,
                           std::vector<std::pair<int,int>> new_scorepoint_enemies,
                           std::pair<int, int> new_player_position,
                           int new_player_scorepoint,
                           int new_player_health) {
    bomb_elements = std::move(new_bomb_elements);
    health_elements = std::move(new_health_elements);
    scorepoint_elements = std::move(new_scorepoint_elements);

    damage_enemies = std::move(new_damage_enemies);
    teleport_enemies = std::move(new_teleport_enemies);
    scorepoint_enemies = std::move(new_scorepoint_enemies);

    player_position = new_player_position;
    player_scorepoint = new_player_scorepoint;
    player_health = new_player_health;
}

std::vector<std::pair<int, int>> FieldMemento::get_bomb_elements() const {
    return bomb_elements;
}

std::vector<std::pair<int, int>> FieldMemento::get_health_elements() const {
    return health_elements;
}

std::vector<std::pair<int, int>> FieldMemento::get_scorepoint_elements() const {
    return scorepoint_elements;
}

std::vector<std::pair<int,int>> FieldMemento::get_teleport_enemies() const {
    return teleport_enemies;
}

std::vector<std::pair<int,int>> FieldMemento::get_damage_enemies() const {
    return damage_enemies;
}

std::vector<std::pair<int,int>> FieldMemento::get_scorepoint_enemies() const {
    return scorepoint_enemies;
}

std::pair<int, int> FieldMemento::get_player_position() const {
    return player_position;
}

int FieldMemento::get_player_scorepoint() const {
    return player_scorepoint;
}

int FieldMemento::get_player_health() const {
    return player_health;
}

void FieldMemento::set_bomb_element(std::pair<int, int> new_bomb_element) {
    bomb_elements.push_back(new_bomb_element);
}

void FieldMemento::set_health_elements(std::pair<int, int> new_health_element) {
    health_elements.push_back(new_health_element);
}

void FieldMemento::set_scorepoint_elements(std::pair<int, int> new_scorepoint_element) {
    scorepoint_elements.push_back(new_scorepoint_element);
}

void FieldMemento::set_teleport_enemies(std::pair<int, int> new_teleport_enemy) {
    teleport_enemies.push_back(new_teleport_enemy);
}

void FieldMemento::set_damage_enemies(std::pair<int, int> new_damage_enemy) {
    damage_enemies.push_back(new_damage_enemy);
}

void FieldMemento::set_scorepoint_enemies(std::pair<int, int> new_scorepoint_enemy) {
    scorepoint_enemies.push_back(new_scorepoint_enemy);
}

void FieldMemento::set_player_position(std::pair<int, int> new_player_position) {
    player_position = new_player_position;
}

void FieldMemento::set_player_scorepoint(int new_player_scorepoint) {
    player_scorepoint = new_player_scorepoint;
}

void FieldMemento::set_player_health(int new_player_health) {
    player_health = new_player_health;
}
