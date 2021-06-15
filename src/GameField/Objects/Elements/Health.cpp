#include "Health.h"

GameObject::ObjectType Health::get_type() const {
    return obj_type;
}

int Health::get_value() const {
    return health_amount;
}

void Health::set_position(int x, int y) {
    position.first = x;
    position.second = y;
}

std::pair<int, int> Health::get_position() const {
    return position;
}

void Health::output_object(std::ostream &output) const {
    output << "Здоровье на позиции (" << position.first << ", " << position.second << ")";
}

const std::string& Health::get_name() const {
    return game_object_name;
}
