#include "SaveLevelCommand.h"

void SaveLevelCommand::execute() {
    GameSettings::get_instance()->save_level();
}
