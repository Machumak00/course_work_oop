#pragma once

#include "Field.h"
#include "Cell.h"

template<class T>
class Enemy {
public:
    void action() {
        Field* field = Field::get_field();
        std::pair<int, int> player_position = player_coord();
        if (player_position == std::make_pair(-1, -1))
            move();
        else
            behavior - field->get_cell(player_position.first, player_position.second).get_player();
    }

    std::pair<int, int> get_position() const {
        return position;
    }

    void set_position(std::pair<int, int> new_position) {
        position = new_position;
    }

    bool is_enemy_moved() {
        return is_moved;
    }

    void set_enemy_moved(bool new_is_moved) {
        is_moved = new_is_moved;
    }

private:
    void move() {
        Field* field = Field::get_field();
        int blocks = 0;
        if (position.first == Field::get_field()->get_size() - 1 ||
            field->get_cell(position.first+1, position.second).get_object() != nullptr ||
            field->get_cell(position.first+1, position.second).get_type() != Cell::Passage) {
            to_right = false;
            blocks++;
        }
        if (position.first == 0 ||
            field->get_cell(position.first-1, position.second).get_object() != nullptr ||
            field->get_cell(position.first-1, position.second).get_type() != Cell::Passage) {
            to_right = true;
            blocks++;
        }
        if (blocks != 2) {
            if (to_right)
                position.first++;
            else
                position.first--;
        }
    }

    std::pair<int, int> player_coord() {
        Field* field = Field::get_field();
        if (position.first != Field::get_field()->get_size()-1) {
            if (field->get_cell(position.first+1, position.second).is_player_on_cell())
                return std::make_pair(position.first+1, position.second);
        }
        if (position.first != 0) {
            if (field->get_cell(position.first-1, position.second).is_player_on_cell())
                return std::make_pair(position.first-1, position.second);
        }
        if (field->get_cell(position.first, position.second-1).is_player_on_cell())
            return std::make_pair(position.first, position.second-1);
        if (field->get_cell(position.first, position.second+1).is_player_on_cell())
            return std::make_pair(position.first, position.second+1);
        return std::pair<int, int> (-1, -1);
    }

    std::pair<int, int> position;
    T behavior;
    bool to_right = true;
    bool is_moved = false;
};