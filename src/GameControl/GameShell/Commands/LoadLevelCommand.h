#pragma once

#include "Command.h"

class LoadLevelCommand : public Command {
public:
    void execute() override;
};
