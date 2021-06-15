#include "StartLevelCommand.h"

void StartLevelCommand::execute() {
    GameSettings::get_instance()->start_level();
}
