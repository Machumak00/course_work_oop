#include "GameStatePlayer.h"
#include "GameStateEnemy.h"
#include "GameSettings.h"
#include "Player.h"
#include "Field.h"
#include "Cell.h"

void GameStatePlayer::actionPlayer() {
    Player* player = GameSettings::get_instance()->get_player();
    sf::Keyboard::Key button = GameSettings::get_instance()->get_button();
    int player_x = player->get_position().first;
    int player_y = player->get_position().second;

    if (button == sf::Keyboard::Up) {
        if (player->get_position().second != 0)
            if (Field::get_field()->get_cell(player_x, player_y - 1).get_type() != Cell::Wall) {
                Field::get_field()->get_cell(player_x, player_y).out_player_from_cell();
                player->set_position(player_x, player_y - 1);
                GameSettings::get_instance()->update_player();
                GameSettings::get_instance()->change_state(new GameStateEnemy);
                GameSettings::get_instance()->action_player_and_enemy();
                GameSettings::get_instance()->move_enemy();
            }
    }
    else if (button == sf::Keyboard::Left) {
        if (player->get_position().first != 0)
            if (Field::get_field()->get_cell(player_x - 1, player_y).get_type() != Cell::Wall) {
                Field::get_field()->get_cell(player_x, player_y).out_player_from_cell();
                player->set_position(player_x - 1, player_y);
                GameSettings::get_instance()->update_player();
                GameSettings::get_instance()->change_state(new GameStateEnemy);
                GameSettings::get_instance()->action_player_and_enemy();
                GameSettings::get_instance()->move_enemy();
            }
    }
    else if (button == sf::Keyboard::Down) {
        if (player->get_position().second != Field::get_field()->get_size() - 1)
            if (Field::get_field()->get_cell(player_x, player_y + 1).get_type() != Cell::Wall) {
                Field::get_field()->get_cell(player_x, player_y).out_player_from_cell();
                player->set_position(player_x, player_y + 1);
                GameSettings::get_instance()->update_player();
                GameSettings::get_instance()->change_state(new GameStateEnemy);
                GameSettings::get_instance()->action_player_and_enemy();
                GameSettings::get_instance()->move_enemy();
            }
    }
    else if (button == sf::Keyboard::Right) {
        if (player->get_position().first != Field::get_field()->get_size() - 1)
            if (Field::get_field()->get_cell(player_x + 1, player_y).get_type() != Cell::Wall) {
                Field::get_field()->get_cell(player_x, player_y).out_player_from_cell();
                player->set_position(player_x + 1, player_y);
                GameSettings::get_instance()->update_player();
                GameSettings::get_instance()->change_state(new GameStateEnemy);
                GameSettings::get_instance()->action_player_and_enemy();
                GameSettings::get_instance()->move_enemy();
            }
    }
}

void GameStatePlayer::actionEnemy() {
    std::cout << "Идёт ход игрока." << std::endl;
}
