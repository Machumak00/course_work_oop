#pragma once

#include "Command.h"

class SaveLevelCommand : public Command {
public:
    void execute() override;
};
