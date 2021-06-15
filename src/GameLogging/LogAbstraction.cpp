#include "LogAbstraction.h"
#include "Observer.h"

LogAbstraction::LogAbstraction(Observer* new_observer) {
    observer = new_observer;
}

void LogAbstraction::add_log(const std::string& str) const{
    observer->update(str);
}
