#pragma once

#include "GameObject.h"

class Bomb : public GameObject {
public:
    GameObject::ObjectType get_type() const override;
    int get_value() const override;
    void set_position(int x, int y) override;
    std::pair<int, int> get_position() const override;
    void output_object(std::ostream& output) const override;
    const std::string& get_name() const override;
private:
    const int damage_amount = 40;
    std::pair<int, int> position;
    GameObject::ObjectType obj_type = GameObject::Bomb;
    const std::string game_object_name = "Бомба";
};
