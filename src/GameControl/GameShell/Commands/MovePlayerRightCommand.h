#pragma once

#include "Command.h"

class MovePlayerRightCommand : public Command {
public:
    void execute() override;
};
