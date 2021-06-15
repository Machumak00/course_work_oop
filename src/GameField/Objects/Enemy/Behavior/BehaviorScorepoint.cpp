#include "BehaviorScorepoint.h"
#include "Player.h"
#include "GameSettings.h"

void BehaviorScorepoint::operator-(Player* player) {
    if (player->get_score() > 0)
        player->set_score(player->get_score() - 5);
    GameSettings::get_instance()->update_player();
}

Behavior::BehaviorType BehaviorScorepoint::get_type() {
    return Behavior::Scorepoint;
}
