#pragma once

#include "GameObjectCreator.h"

class BombCreator : public GameObjectCreator {
public:
    GameObject* CreateGameObject() const override;
};
