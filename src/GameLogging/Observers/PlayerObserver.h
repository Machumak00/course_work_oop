#pragma once

#include "Observer.h"

class PlayerObserver : public Observer {
public:
    void update(const std::string& new_str) override;
};
