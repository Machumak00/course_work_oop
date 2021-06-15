#include "HealthCreator.h"
#include "Health.h"

GameObject* HealthCreator::CreateGameObject() const {
    return new Health;
}
