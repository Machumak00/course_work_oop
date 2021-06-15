#pragma once

#include "GameControl/GameShell/GameSettings.h"

class Command {
public:
    virtual void execute() = 0;
};
