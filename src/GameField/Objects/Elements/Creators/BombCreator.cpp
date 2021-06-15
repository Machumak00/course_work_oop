#include "BombCreator.h"
#include "Bomb.h"

GameObject* BombCreator::CreateGameObject() const {
    return new Bomb;
}
