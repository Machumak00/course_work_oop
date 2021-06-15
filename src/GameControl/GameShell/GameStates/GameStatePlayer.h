#pragma once

#include "GameState.h"

class GameStatePlayer : public GameState {
public:
    void actionPlayer() override;
    void actionEnemy() override;
};