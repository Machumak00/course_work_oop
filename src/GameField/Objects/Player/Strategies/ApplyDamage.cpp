#include "ApplyDamage.h"
#include "Cell.h"
#include "Field.h"

void ApplyDamage::apply_element(const GameObject& damage, Player &player) const {
    player.set_health(player.get_health() - damage.get_value());
    if (player.get_health() <= 0)
        player.set_player_died();
    Field::get_field()->get_cell(player.get_position().first, player.get_position().second).set_nobody_object();
}
