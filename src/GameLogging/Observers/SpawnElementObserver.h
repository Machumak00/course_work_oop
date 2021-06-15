#pragma once

#include "Observer.h"

class SpawnElementObserver : public Observer {
public:
    void update(const std::string& new_str) override;
};
