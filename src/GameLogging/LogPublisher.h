#pragma once

#include "libraries.h"

class Observer;
class LogPublisher{
public:
    enum Publisher{PlayerInfo, SpawnElementInfo, MeetElementInfo, GameOverInfo, LevelStart};
    void Attach(Observer* observer, Publisher publisher);
    void Detach(Observer* observer);
    void Notify(Publisher implementation, const std::string& new_str);
private:
    std::map<Observer*, Publisher> observers;
};
