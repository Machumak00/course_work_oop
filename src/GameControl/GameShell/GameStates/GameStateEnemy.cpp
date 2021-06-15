#include "GameStateEnemy.h"
#include "Enemy.hpp"
#include "BehaviorDamage.h"
#include "BehaviorTeleport.h"
#include "BehaviorScorepoint.h"
#include "GameSettings.h"
#include "GameStatePlayer.h"

void GameStateEnemy::actionPlayer() {
    std::cout << "Идёт ход врага." << std::endl;
}

void GameStateEnemy::actionEnemy() {
    Field* field = Field::get_field();
    int field_size = field->get_size();
    for(int i = 0; i < field_size; ++i) {
        for(int j = 0; j < field_size; ++j) {
            if (field->get_cell(i, j).is_enemy_on_cell()) {
                if (field->get_cell(i, j).is_enemy_damage_on_cell()) {
                    Enemy<BehaviorDamage>* enemy = field->get_cell(i, j).get_enemy_damage();
                    if (!enemy->is_enemy_moved()) {
                        field->get_cell(i, j).out_enemy_from_cell();
                        enemy->action();
                        field->get_cell(enemy->get_position().first, enemy->get_position().second).set_enemy_damage(enemy);
                        enemy->set_enemy_moved(true);
                    }
                }
                else if (field->get_cell(i, j).is_enemy_scorepoint_on_cell()) {
                    Enemy<BehaviorScorepoint> *enemy = field->get_cell(i, j).get_enemy_scorepoint();
                    if (!enemy->is_enemy_moved()) {
                        field->get_cell(i, j).out_enemy_from_cell();
                        enemy->action();
                        field->get_cell(enemy->get_position().first, enemy->get_position().second).set_enemy_scorepoint(enemy);
                        enemy->set_enemy_moved(true);
                    }
                }
                else {
                    Enemy<BehaviorTeleport>* enemy = field->get_cell(i, j).get_enemy_teleport();
                    if (!enemy->is_enemy_moved()) {
                        field->get_cell(i, j).out_enemy_from_cell();
                        enemy->action();
                        field->get_cell(enemy->get_position().first, enemy->get_position().second).set_enemy_teleport(enemy);
                        enemy->set_enemy_moved(true);
                    }
                }
            }
        }
    }
    for(int i = 0; i < field_size; ++i) {
        for(int j = 0; j < field_size; ++j) {
            if (field->get_cell(i, j).is_enemy_damage_on_cell())
                field->get_cell(i, j).get_enemy_damage()->set_enemy_moved(false);
            else if (field->get_cell(i, j).is_enemy_scorepoint_on_cell())
                field->get_cell(i, j).get_enemy_scorepoint()->set_enemy_moved(false);
            else if (field->get_cell(i, j).is_enemy_teleport_on_cell())
                field->get_cell(i, j).get_enemy_teleport()->set_enemy_moved(false);
        }
    }
    GameSettings::get_instance()->change_state(new GameStatePlayer);
}
