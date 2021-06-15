#include "BehaviorTeleport.h"
#include "Player.h"
#include "Field.h"
#include "Cell.h"
#include "GameSettings.h"

void BehaviorTeleport::operator-(Player* player) {
    if (power) {
        Field::get_field()->get_cell(player->get_position().first, player->get_position().second).out_player_from_cell();
        player->set_position(0, 0);
        Field::get_field()->get_cell(0, 0).set_player_on_cell(player);
        GameSettings::get_instance()->update_player();
    }
    power--;
}

Behavior::BehaviorType BehaviorTeleport::get_type() {
    return Behavior::Teleport;
}
