#pragma once

#include "Observer.h"

class GameOverObserver : public Observer {
public:
    void update(const std::string& new_str) override;
};
