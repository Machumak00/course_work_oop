#pragma once

#include "GameObjectCreator.h"

class ScorePointCreator : public GameObjectCreator {
public:
    GameObject* CreateGameObject() const override;
};
