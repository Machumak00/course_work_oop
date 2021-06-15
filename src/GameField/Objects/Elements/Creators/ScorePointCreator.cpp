#include "ScorePointCreator.h"
#include "ScorePoint.h"

GameObject* ScorePointCreator::CreateGameObject() const {
    return new ScorePoint;
}