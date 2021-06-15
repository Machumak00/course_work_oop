#include "MovePlayerLeftCommand.h"

void MovePlayerLeftCommand::execute() {
    GameSettings::get_instance()->set_button(sf::Keyboard::Left);
    GameSettings::get_instance()->move_player();
}
