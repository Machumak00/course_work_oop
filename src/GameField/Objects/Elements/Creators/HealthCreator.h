#pragma once

#include "GameObjectCreator.h"

class HealthCreator : public GameObjectCreator {
public:
    GameObject* CreateGameObject() const override;
};
