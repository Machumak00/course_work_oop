#pragma once

#include "libraries.h"

class Observer;
class LogAbstraction {
public:
    LogAbstraction(Observer* new_observer);
    virtual void add_log(const std::string& new_str) const;
    virtual ~LogAbstraction() = default;
private:
    Observer* observer;
};
