#include "ApplyScorePoint.h"
#include "Cell.h"
#include "Field.h"

void ApplyScorePoint::apply_element(const GameObject& score_point, Player& player) const {
    player.set_score(player.get_score() + score_point.get_value());
    Field::get_field()->get_cell(player.get_position().first, player.get_position().second).set_nobody_object();
}
