#include "MovePlayerRightCommand.h"

void MovePlayerRightCommand::execute() {
    GameSettings::get_instance()->set_button(sf::Keyboard::Right);
    GameSettings::get_instance()->move_player();
}
