#pragma once

#include "GameState.h"

class GameStateEnemy : public GameState {
public:
    void actionPlayer() override;
    void actionEnemy() override;
};
