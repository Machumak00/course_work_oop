#pragma once

#include "Observer.h"

class LevelStartObserver : public Observer {
public:
    void update(const std::string& new_str) override;
};
