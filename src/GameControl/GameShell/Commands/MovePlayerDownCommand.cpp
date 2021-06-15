#include "MovePlayerDownCommand.h"

void MovePlayerDownCommand::execute() {
    GameSettings::get_instance()->set_button(sf::Keyboard::Down);
    GameSettings::get_instance()->move_player();
}
