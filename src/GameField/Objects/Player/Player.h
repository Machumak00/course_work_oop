#pragma once

#include "GameObject.h"

class BehaviorDamage;
class BehaviorTeleport;
class BehaviorScorepoint;
template<class T> class Enemy;
class Player {
public:
    explicit Player(int new_health_amount = 100, int new_score_amount = 0, int x = 0, int y = 0);
    void set_position(int x, int y);
    std::pair<int, int> get_position() const;
    int get_health() const;
    void set_health(int health);
    int get_score() const;
    void set_score(int score);
    Player& operator=(const Player& new_player);
    Player& operator+(const GameObject& game_object);
    bool is_player_died() const;
    void set_player_died();
    friend std::ostream& operator<<(std::ostream& output, const Player& player);
    std::string get_use_element_string() const;
    void clear_use_element_string();
    void operator-(Enemy<BehaviorDamage>* enemy);
    void operator-(Enemy<BehaviorScorepoint>* enemy);
    void operator-(Enemy<BehaviorTeleport>* enemy);
    void reset();
private:
    int health_amount;
    int score_amount;
    std::string use_element_string;
    bool is_died;
    std::pair<int, int> position;
};
