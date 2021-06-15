#pragma once

#include "libraries.h"
#include "Cell.h"
#include "Field.h"

class CellView;
class GameView {
public:
    GameView();
    ~GameView();
    enum GameTextures {NewGameTexture, ExitGameTexture};
    sf::RenderWindow* get_window() const;
    void draw_field();
    sf::Sprite* get_game_image(GameTextures game_texture) const;
private:
    sf::RenderWindow* game;
    const int window_size = Cell::get_size() * Field::get_field()->get_size();
    sf::Texture* new_game_texture;
    sf::Texture* exit_game_texture;
    sf::Sprite* new_game_sprite;
    sf::Sprite* exit_game_sprite;
    CellView* cell_view;
};
