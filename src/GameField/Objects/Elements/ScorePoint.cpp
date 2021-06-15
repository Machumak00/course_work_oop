#include "ScorePoint.h"

GameObject::ObjectType ScorePoint::get_type() const {
    return obj_type;
}

int ScorePoint::get_value() const {
    return score_amount;
}

void ScorePoint::set_position(int x, int y) {
    position.first = x;
    position.second = y;
}

std::pair<int, int> ScorePoint::get_position() const {
    return position;
}

void ScorePoint::output_object(std::ostream &output) const {
    output << "Очки на позиции (" << position.first << ", " << position.second << ")";
}

const std::string& ScorePoint::get_name() const {
    return game_object_name;
}
