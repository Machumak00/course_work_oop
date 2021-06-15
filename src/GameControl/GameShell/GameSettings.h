#pragma once

#include "libraries.h"

class LogPublisher;
class Observer;
class Player;
class GameState;
class Snapshot;
class GameSettings{
public:
    static GameSettings* get_instance();
    void delete_instance();
    void start_level();
    void end_level();
    bool game_over() const;
    void change_state(GameState* game_state);
    void move_player();
    void move_enemy();
    sf::Keyboard::Key get_button() const;
    void set_button(sf::Keyboard::Key new_button);
    Player* get_player() const;
    void update_player();
    void action_player_and_enemy();
    void clear_field();
    void load_level();
    void save_level();
private:
    explicit GameSettings();
    ~GameSettings();
    GameSettings(const GameSettings& other_game_settings);
    GameSettings(GameSettings&& other_game_settings);
    GameSettings& operator=(const GameSettings& other_game_settings);
    GameSettings& operator=(GameSettings&& tmp_settings);
    void attach_observers();
    void create_snapshot();
    Snapshot* snapshot;
    Player* player;
    LogPublisher* log_publisher;
    Observer* observers[5];
    void log_spawn_game_objects();
    bool is_game_over;
    static GameSettings* game_settings_ptr;
    GameState* game_state;
    sf::Keyboard::Key button;
};
