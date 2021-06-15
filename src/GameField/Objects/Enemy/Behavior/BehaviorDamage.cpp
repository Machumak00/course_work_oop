#include "BehaviorDamage.h"
#include "Player.h"
#include "GameSettings.h"

void BehaviorDamage::operator-(Player* player) {
    player->set_health(player->get_health() - 20);
    if (player->get_health() == 0)
        player->set_player_died();
    GameSettings::get_instance()->update_player();
}

Behavior::BehaviorType BehaviorDamage::get_type() {
    return Behavior::Damage;
}
