#pragma once

#include "libraries.h"

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& new_str) = 0;
};
