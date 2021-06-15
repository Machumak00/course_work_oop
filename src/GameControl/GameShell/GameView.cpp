#include "GameView.h"
#include "FieldIterator.h"
#include "CellView.h"

GameView::GameView() {
    game = new sf::RenderWindow;
    cell_view = new CellView;
    game->create(sf::VideoMode(window_size, window_size), "Game!");

    new_game_texture = new sf::Texture;
    exit_game_texture = new sf::Texture;

    new_game_sprite = new sf::Sprite;
    exit_game_sprite = new sf::Sprite;

    new_game_texture->loadFromFile("Sprites/Menu/NewGameSprite.png");
    exit_game_texture->loadFromFile("Sprites/Menu/ExitGameSprite.png");

    new_game_sprite->setTexture(*new_game_texture);
    exit_game_sprite->setTexture(*exit_game_texture);

    new_game_sprite->setPosition(160, 60);
    exit_game_sprite->setPosition(160, 120);
}

GameView::~GameView() {
    delete game;

    delete new_game_texture;
    delete exit_game_texture;

    delete new_game_sprite;
    delete exit_game_sprite;

    delete cell_view;
}

sf::RenderWindow* GameView::get_window() const {
    return game;
}

void GameView::draw_field() {
    FieldIterator field_it;
    for(field_it.entry(); !field_it.isEnd(); field_it.next()) {
        cell_view->set_cell(field_it.getElem());
        cell_view->choose_image();
        game->draw(cell_view->get_cell_view());
    }
    cell_view->set_cell(field_it.getElem());
    cell_view->choose_image();
    game->draw(cell_view->get_cell_view());
}

sf::Sprite* GameView::get_game_image(GameView::GameTextures game_texture) const {
    if (game_texture == NewGameTexture)
        return new_game_sprite;
    else if (game_texture == ExitGameTexture)
        return exit_game_sprite;
}
