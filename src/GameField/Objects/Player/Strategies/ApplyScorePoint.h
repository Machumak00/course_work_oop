#pragma once

#include "ApplyElement.h"

class ApplyScorePoint : public ApplyElement {
public:
    void apply_element(const GameObject& score_point, Player& player) const override;
};
