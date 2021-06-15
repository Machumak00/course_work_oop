#include "LoadLevelCommand.h"

void LoadLevelCommand::execute() {
    GameSettings::get_instance()->load_level();
}
