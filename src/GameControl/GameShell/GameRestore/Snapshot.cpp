#include "Snapshot.h"

#include <utility>
#include "Field.h"
#include "Cell.h"
#include "GameSettings.h"
#include "Player.h"
#include "BehaviorDamage.h"
#include "BehaviorScorepoint.h"
#include "BehaviorTeleport.h"
#include "Enemy.hpp"
#include "Bomb.h"
#include "ScorePoint.h"
#include "Health.h"

Snapshot::Snapshot() {
    field_memento = new FieldMemento;
}

Snapshot::Snapshot(
        std::vector<std::pair<int,int>> new_bomb_elements,
        std::vector<std::pair<int,int>> new_health_elements,
        std::vector<std::pair<int,int>> new_scorepoint_elements,
        std::vector<std::pair<int,int>> new_damage_enemies,
        std::vector<std::pair<int,int>> new_teleport_enemies,
        std::vector<std::pair<int,int>> new_scorepoint_enemies,
        std::pair<int, int> new_player_position,
        int new_player_scorepoint,
        int new_player_health) {
    field_memento = new FieldMemento(
            std::move(new_bomb_elements), std::move(new_health_elements),std::move(new_scorepoint_elements),
            std::move(new_damage_enemies), std::move(new_teleport_enemies), std::move(new_scorepoint_enemies),
            new_player_position, new_player_scorepoint, new_player_health);
}

FieldMemento* Snapshot::get_memento() const {
    return field_memento;
}

void Snapshot::restore() {
    for (int i = 0; i < Field::get_field()->get_size(); ++i) {
        for (int j = 0; j < Field::get_field()->get_size(); ++j) {
            Field::get_field()->get_cell(i, j).delete_enemy();
            Field::get_field()->get_cell(i, j).out_player_from_cell();
            Field::get_field()->get_cell(i, j).set_nobody_object();
        }
    }

    GameSettings::get_instance()->get_player()->set_position(get_memento()->get_player_position().first, get_memento()->get_player_position().second);
    GameSettings::get_instance()->get_player()->set_score(get_memento()->get_player_scorepoint());
    GameSettings::get_instance()->get_player()->set_health(get_memento()->get_player_health());

    for(const auto& i : field_memento->get_damage_enemies())
        Field::get_field()->get_cell(i.first, i.second).set_enemy_damage(new Enemy<BehaviorDamage>);
    for(const auto& i : field_memento->get_scorepoint_enemies())
        Field::get_field()->get_cell(i.first, i.second).set_enemy_scorepoint(new Enemy<BehaviorScorepoint>);
    for(const auto& i : field_memento->get_teleport_enemies())
        Field::get_field()->get_cell(i.first, i.second).set_enemy_teleport(new Enemy<BehaviorTeleport>);

    for(const auto& i : field_memento->get_bomb_elements())
        Field::get_field()->get_cell(i.first, i.second).set_object(new Bomb);
    for(const auto& i : field_memento->get_scorepoint_elements())
        Field::get_field()->get_cell(i.first, i.second).set_object(new ScorePoint);
    for(const auto& i : field_memento->get_health_elements())
        Field::get_field()->get_cell(i.first, i.second).set_object(new Health);
}
