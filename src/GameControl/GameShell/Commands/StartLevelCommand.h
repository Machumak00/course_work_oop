#pragma once

#include "Command.h"

class StartLevelCommand : public Command {
public:
    void execute() override;
};
