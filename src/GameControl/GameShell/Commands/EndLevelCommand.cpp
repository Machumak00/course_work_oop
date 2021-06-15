#include "EndLevelCommand.h"

void EndLevelCommand::execute() {
    GameSettings::get_instance()->end_level();
}

bool EndLevelCommand::game_is_over() {
    if (GameSettings::get_instance()->game_over()) {
        return true;
    }
    return false;
}
