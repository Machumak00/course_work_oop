#pragma once

#include "GameObject.h"

class GameObjectCreator {
public:
    virtual GameObject* CreateGameObject() const = 0;
};
