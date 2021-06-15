#pragma once

#include "libraries.h"

class Observer;
class GameObject {
public:
    enum ObjectType {Nobody, Bomb, ScorePoint, Health};
    virtual ~GameObject() = default;
    virtual GameObject::ObjectType get_type() const = 0;
    virtual void set_position(int x, int y) = 0;
    virtual std::pair<int, int> get_position() const = 0;
    virtual int get_value() const = 0;
    virtual const std::string& get_name() const = 0;
    virtual void output_object(std::ostream& output) const = 0;
    friend std::ostream& operator<<(std::ostream& output, const GameObject& game_object);
};
