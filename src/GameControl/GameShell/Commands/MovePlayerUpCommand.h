#pragma once

#include "Command.h"

class MovePlayerUpCommand : public Command {
public:
    void execute() override;
};
