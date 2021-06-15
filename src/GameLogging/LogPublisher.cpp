#include "LogPublisher.h"
#include "LogAbstraction.h"

void LogPublisher::Attach(Observer* observer, Publisher publisher) {
    observers[observer] = publisher;
}

void LogPublisher::Detach(Observer* observer) {
    observers.erase(observer);
}

void LogPublisher::Notify(Publisher publisher, const std::string& new_str) {
    for (auto iterator : observers)
        if (iterator.second == publisher) {
            LogAbstraction log_abstraction(iterator.first);
            log_abstraction.add_log(new_str);
        }
}
