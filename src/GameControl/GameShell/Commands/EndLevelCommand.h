#pragma once

#include "Command.h"

class EndLevelCommand : public Command {
public:
    void execute() override;
    bool game_is_over();
};
