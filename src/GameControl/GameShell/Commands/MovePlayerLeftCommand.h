#pragma once

#include "Command.h"

class MovePlayerLeftCommand : public Command {
public:
    void execute() override;
};
