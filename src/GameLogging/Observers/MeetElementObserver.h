#pragma once

#include "Observer.h"

class MeetElementObserver : public Observer {
public:
    void update(const std::string& new_str) override;
};
