#pragma once

#include "libraries.h"

class GameState {
public:
    virtual void actionPlayer() = 0;
    virtual void actionEnemy() = 0;
};