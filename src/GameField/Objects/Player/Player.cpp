#include "Player.h"
#include "Field.h"
#include "ApplyToPlayer.h"
#include "Enemy.hpp"
#include "Cell.h"

Player::Player(int new_health_amount, int new_score_amount, int x, int y){
    health_amount = new_health_amount;
    score_amount = new_score_amount;
    position.first = x;
    position.second = y;
    is_died = false;
}

void Player::set_position(int x, int y) {
    position.first = x;
    position.second = y;
}

std::pair<int, int> Player::get_position() const {
    return position;
}

int Player::get_health() const {
    return health_amount;
}

void Player::set_health(int health) {
    if (health_amount > health)
        use_element_string = "На игрока подействовал урон в размере " + std::to_string(health_amount - health) + " единиц жизней.\n";
    else if (health_amount < health)
        use_element_string = "Игрок восполнил здоровье на " + std::to_string(health - health_amount) + " единиц жизней.\n";
    health_amount = health;
}

int Player::get_score() const {
    return score_amount;
}

void Player::set_score(int score) {
    if (score_amount < score)
        use_element_string = "Игрок получил " + std::to_string(score - score_amount) + " очков.\n";
    else if (score_amount > score)
        use_element_string = "Игрок потерял " + std::to_string(score_amount - score) + " очков.\n";
    score_amount = score;
}

Player& Player::operator=(const Player& new_player) {
    if (&new_player == this)
        return *this;
    position.first = new_player.position.first;
    position.second = new_player.position.second;
    health_amount = new_player.health_amount;
    score_amount = new_player.score_amount;
    return *this;
}

Player& Player::operator+(const GameObject& game_object) {
    auto* apply_to_player = new ApplyToPlayer;
    GameObject::ObjectType object_type = Field::get_field()->get_cell(get_position().first, get_position().second).get_object()->get_type();
    if (object_type != GameObject::Nobody) {
        apply_to_player->choose_strategy(object_type);
        apply_to_player->apply_element_to_player(game_object, *this);
    }
    delete apply_to_player;
    return *this;
}

bool Player::is_player_died() const {
    return is_died;
}

void Player::set_player_died() {
    is_died = true;
}

std::ostream& operator<<(std::ostream& output, const Player& player) {
    output << player.get_use_element_string() + "Игрок располагается на позиции (" << player.get_position().first << ", " << player.get_position().second
    << "). У игрока " << player.get_health() << " здоровья и " << player.get_score() << " очков.";
    if (player.is_player_died())
        output << std::endl << "Игрок погиб на позиции ("
        << player.get_position().first << ", " << player.get_position().second << ").";
    return output;
}

std::string Player::get_use_element_string() const {
    return use_element_string;
}

void Player::clear_use_element_string() {
    use_element_string.clear();
}

void Player::operator-(Enemy<BehaviorDamage>* enemy) {
    Field* field = Field::get_field();
    field->get_cell(position.first, position.second).delete_enemy();
}

void Player::operator-(Enemy<BehaviorScorepoint>* enemy){
    Field* field = Field::get_field();
    field->get_cell(position.first, position.second).delete_enemy();
}

void Player::operator-(Enemy<BehaviorTeleport>* enemy){
    Field* field = Field::get_field();
    field->get_cell(position.first, position.second).delete_enemy();
}

void Player::reset() {
    health_amount = 100;
    score_amount = 0;
    is_died = false;
    position = std::make_pair(0, 0);
}
