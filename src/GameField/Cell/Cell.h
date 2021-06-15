#pragma once

#include "libraries.h"
#include "GameObject.h"

class Player;
class BehaviorDamage;
class BehaviorScorepoint;
class BehaviorTeleport;
template<class T> class Enemy;
class Cell {
public:
    enum CellType {Passage, Wall, Entry, Exit};
    Cell();
    ~Cell();
    Cell& operator=(const Cell& new_cell);
    static int get_size();
    void set_position(int x, int y);
    std::pair<int, int> get_position() const;
    CellType get_type() const;
    void set_type(CellType new_cell_type);
    void set_object(GameObject* new_game_object);
    void set_nobody_object();
    GameObject* get_object() const;
    void set_player_on_cell(Player* player);
    void out_player_from_cell();
    bool is_enemy_on_cell() const;
    bool is_player_on_cell() const;
    bool is_enemy_damage_on_cell() const;
    bool is_enemy_scorepoint_on_cell() const;
    bool is_enemy_teleport_on_cell() const;
    Player* get_player() const;
    void set_enemy_damage(Enemy<BehaviorDamage>* new_enemy_damage);
    void set_enemy_scorepoint(Enemy<BehaviorScorepoint>* new_enemy_scorepoint);
    void set_enemy_teleport(Enemy<BehaviorTeleport>* new_enemy_teleport);
    Enemy<BehaviorDamage>* get_enemy_damage();
    Enemy<BehaviorScorepoint>* get_enemy_scorepoint();
    Enemy<BehaviorTeleport>* get_enemy_teleport();
    void out_enemy_from_cell();
    void delete_enemy();
private:
    static const int size = 35;
    std::pair<int, int> position;
    GameObject::ObjectType object_type;
    GameObject* game_object;
    Player* player;
    Enemy<BehaviorDamage>* enemy_damage;
    Enemy<BehaviorScorepoint>* enemy_scorepoint;
    Enemy<BehaviorTeleport>* enemy_teleport;
    bool is_enemy_damage;
    bool is_enemy_scorepoint;
    bool is_enemy_teleport;
    CellType cell_type;
    bool is_player;
};
