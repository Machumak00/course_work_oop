#pragma once

#include "libraries.h"

class Cell;
class CellView {
public:
    CellView();
    void set_cell(Cell* new_cell);
    void choose_image();
    sf::Sprite get_cell_view() const;
private:
    sf::Texture bomb_texture;
    sf::Texture health_texture;
    sf::Texture scorepoint_texture;
    sf::Texture entry_cell_texture;
    sf::Texture exit_cell_texture;
    sf::Texture passage_cell_texture;
    sf::Texture wall_cell_texture;
    sf::Texture player_texture;
    sf::Texture enemy_scorepoint_texture;
    sf::Texture enemy_damage_texture;
    sf::Texture enemy_teleport_texture;
    sf::Sprite cell_image;
    Cell* cell;
};
