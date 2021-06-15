#include "Game.h"
#include "GameCommands.h"
#include "GameView.h"
#include "GameStatePlayer.h"

Game::Game() {
    game_view = new GameView;
    game_commands = new GameCommands;
    game = game_view->get_window();
    menu_num = 0;
}

Game::~Game() {
    delete game_view;
    delete game_commands;
}

void Game::start_game() {
    while (game->isOpen()) {
        check_menu_num();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (menu_num == 1) {
                GameSettings::get_instance()->change_state(new GameStatePlayer);
                start_level();
                if (!game->isOpen())
                    game->close();
            }
            if (menu_num == 2)
                game->close();
        }
        draw_menu();
    }
    GameSettings::get_instance()->delete_instance();
}

void Game::save_level() {
    game_commands->execute(GameCommands::SaveLevel);
}

void Game::load_level() {
    game_commands->execute(GameCommands::LoadLevel);
}

void Game::start_level() {
    game_commands->execute(GameCommands::StartLevel);
    check_end_level();
    while (!game_commands->game_over() && game->isOpen()){
        sf::Event event;
        game_view->draw_field();
        while (game->pollEvent(event))
            switch (event.type){
                case sf::Event::Closed:
                    game->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::F5)
                        save_level();
                    if (event.key.code == sf::Keyboard::F9)
                        load_level();
                    if (event.key.code == sf::Keyboard::Up)
                        game_commands->execute(GameCommands::MovePlayerUp);
                    else if (event.key.code == sf::Keyboard::Left)
                        game_commands->execute(GameCommands::MovePlayerLeft);
                    else if (event.key.code == sf::Keyboard::Down)
                        game_commands->execute(GameCommands::MovePlayerDown);
                    else if (event.key.code == sf::Keyboard::Right)
                        game_commands->execute(GameCommands::MovePlayerRight);
                    is_key_pressed = true;
                    break;
                case sf::Event::KeyReleased:
                    if (is_key_pressed)
                        is_key_pressed = false;
                    break;
                default:
                    break;
            }
        check_end_level();
        game->display();
    }
    GameSettings::get_instance()->clear_field();
}

void Game::check_end_level() {
    game_commands->execute(GameCommands::EndLevel);
}

void Game::draw_menu() {
    game->draw(*game_view->get_game_image(GameView::NewGameTexture));
    game->draw(*game_view->get_game_image(GameView::ExitGameTexture));
    game->display();
}

void Game::check_menu_num() {
    game_view->get_game_image(GameView::NewGameTexture)->setColor(sf::Color::White);
    game_view->get_game_image(GameView::ExitGameTexture)->setColor(sf::Color::White);
    game->clear(sf::Color(129, 181, 221));
    if (sf::IntRect(160, 60, 160, 40).contains(sf::Mouse::getPosition(*game))) {
        game_view->get_game_image(GameView::NewGameTexture)->setColor(sf::Color::Blue);
        menu_num = 1;
    }
    else if (sf::IntRect(160, 120, 160, 40).contains(sf::Mouse::getPosition(*game))) {
        game_view->get_game_image(GameView::ExitGameTexture)->setColor(sf::Color::Blue);
        menu_num = 2;
    }
    else
        menu_num = 0;
}