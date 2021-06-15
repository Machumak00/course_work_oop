#include "ApplyToPlayer.h"
#include "ApplyElement.h"
#include "ApplyDamage.h"
#include "ApplyScorePoint.h"
#include "ApplyHealth.h"

ApplyToPlayer::ApplyToPlayer(ApplyElement* new_apply_element) {
    apply_element = new_apply_element;
}

ApplyToPlayer::~ApplyToPlayer() {
    delete this->apply_element;
}

void ApplyToPlayer::set_strategy(ApplyElement* new_apply_element) {
    delete apply_element;
    apply_element = new_apply_element;
}

void ApplyToPlayer::choose_strategy(GameObject::ObjectType obj) {
    if (obj == GameObject::Bomb)
        set_strategy(new ApplyDamage);
    else if (obj == GameObject::ScorePoint)
        set_strategy(new ApplyScorePoint);
    else if (obj == GameObject::Health)
        set_strategy(new ApplyHealth);
}

void ApplyToPlayer::apply_element_to_player(const GameObject& object, Player& player) const {
    apply_element->apply_element(object, player);
}