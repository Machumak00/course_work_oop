#include "ApplyHealth.h"
#include "Cell.h"
#include "Field.h"

void ApplyHealth::apply_element(const GameObject& health, Player& player) const {
    if (player.get_health() <= 80) {
        player.set_health(player.get_health() + health.get_value());
        Field::get_field()->get_cell(player.get_position().first, player.get_position().second).set_nobody_object();
    }
}
