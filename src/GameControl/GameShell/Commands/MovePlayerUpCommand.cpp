#include "MovePlayerUpCommand.h"

void MovePlayerUpCommand::execute() {
    GameSettings::get_instance()->set_button(sf::Keyboard::Up);
    GameSettings::get_instance()->move_player();
}
