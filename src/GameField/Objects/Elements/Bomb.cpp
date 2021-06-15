#include "Bomb.h"

GameObject::ObjectType Bomb::get_type() const {
    return obj_type;
}

int Bomb::get_value() const {
    return damage_amount;
}

void Bomb::set_position(int x, int y) {
    position.first = x;
    position.second = y;
}

std::pair<int, int> Bomb::get_position() const {
    return position;
}

void Bomb::output_object(std::ostream &output) const {
    output << "Бомба на позиции (" << position.first << ", " << position.second << ")";
}

const std::string& Bomb::get_name() const {
    return game_object_name;
}
