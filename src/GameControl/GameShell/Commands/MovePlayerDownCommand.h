#pragma once

#include "Command.h"

class MovePlayerDownCommand : public Command {
public:
    void execute() override;
};
