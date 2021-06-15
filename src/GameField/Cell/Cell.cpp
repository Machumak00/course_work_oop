#include "Cell.h"
#include "Enemy.hpp"
#include "Player.h"
#include "BehaviorTeleport.h"
#include "BehaviorScorepoint.h"
#include "BehaviorDamage.h"

Cell::Cell() {
    position.first = 0;
    position.second = 0;
    object_type = GameObject::Nobody;
    cell_type = Passage;
    is_player = false;
    is_enemy_damage = false;
    is_enemy_scorepoint = false;
    is_enemy_teleport = false;
    game_object = nullptr;
    player = nullptr;
    enemy_damage = nullptr;
    enemy_teleport = nullptr;
    enemy_scorepoint = nullptr;
}

Cell::~Cell() {
    if (game_object != nullptr) {
        delete game_object;
        game_object = nullptr;
    }
    delete_enemy();
}

Cell& Cell::operator=(const Cell& new_cell) {
    position.first = new_cell.position.first;
    position.second = new_cell.position.second;
    object_type = new_cell.object_type;
    cell_type = new_cell.cell_type;
    is_player = new_cell.is_player;
    game_object = new_cell.game_object;
    return *this;
}

int Cell::get_size() {
    return size;
}

void Cell::set_player_on_cell(Player* new_player) {
    player = new_player;
    is_player = true;
}

void Cell::out_player_from_cell() {
    is_player = false;
}

void Cell::set_position(int x, int y) {
    position.first = x;
    position.second = y;
}

std::pair<int, int> Cell::get_position() const {
    return position;
}

Cell::CellType Cell::get_type() const {
    return cell_type;
}

void Cell::set_type(Cell::CellType new_cell_type) {
    cell_type = new_cell_type;
}

void Cell::set_object(GameObject* new_game_object) {
    object_type = new_game_object->get_type();
    game_object = new_game_object;
    game_object->set_position(position.first, position.second);
}

void Cell::set_nobody_object() {
    object_type = GameObject::Nobody;
    delete game_object;
    game_object = nullptr;
}

GameObject* Cell::get_object() const {
    return game_object;
}

bool Cell::is_player_on_cell() const {
    return is_player;
}

bool Cell::is_enemy_on_cell() const {
    if (is_enemy_damage_on_cell() || is_enemy_teleport_on_cell() || is_enemy_scorepoint_on_cell())
        return true;
    else
        return false;
}

Player* Cell::get_player() const {
    return player;
}

void Cell::set_enemy_damage(Enemy<BehaviorDamage> *new_enemy_damage) {
    enemy_damage = new_enemy_damage;
    enemy_damage->set_position(position);
    is_enemy_damage = true;
}

void Cell::set_enemy_scorepoint(Enemy<BehaviorScorepoint> *new_enemy_scorepoint) {
    enemy_scorepoint = new_enemy_scorepoint;
    enemy_scorepoint->set_position(position);
    is_enemy_scorepoint = true;
}

void Cell::set_enemy_teleport(Enemy<BehaviorTeleport> *new_enemy_teleport) {
    enemy_teleport = new_enemy_teleport;
    enemy_teleport->set_position(position);
    is_enemy_teleport = true;
}

Enemy<BehaviorDamage>* Cell::get_enemy_damage() {
    return enemy_damage;
}

Enemy<BehaviorScorepoint>* Cell::get_enemy_scorepoint() {
    return enemy_scorepoint;
}

Enemy<BehaviorTeleport>* Cell::get_enemy_teleport() {
    return enemy_teleport;
}

void Cell::out_enemy_from_cell() {
    enemy_damage = nullptr;
    enemy_teleport = nullptr;
    enemy_scorepoint = nullptr;
    is_enemy_scorepoint = false;
    is_enemy_teleport = false;
    is_enemy_damage = false;
}

bool Cell::is_enemy_damage_on_cell() const {
    return is_enemy_damage;
}

bool Cell::is_enemy_scorepoint_on_cell() const {
    return is_enemy_scorepoint;
}

bool Cell::is_enemy_teleport_on_cell() const {
    return is_enemy_teleport;
}

void Cell::delete_enemy() {
    if (enemy_teleport != nullptr) {
        delete enemy_teleport;
        enemy_teleport = nullptr;
    }
    if (enemy_damage != nullptr) {
        delete enemy_damage;
        enemy_damage = nullptr;
    }
    if (enemy_scorepoint != nullptr) {
        delete enemy_scorepoint;
        enemy_scorepoint = nullptr;
    }
    out_enemy_from_cell();
}
