#pragma once

#include "libraries.h"

class GameView;
class GameCommands;
class Game {
public:
    Game();
    ~Game();
    void start_game();
private:
    void start_level();
    void save_level();
    void load_level();
    void check_end_level();
    void check_menu_num();
    void draw_menu();
    GameCommands* game_commands;
    GameView* game_view;
    sf::RenderWindow* game;
    int menu_num;
    bool is_key_pressed = false;
};
