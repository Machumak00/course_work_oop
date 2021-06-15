#pragma once

#include "libraries.h"

class Cell;
class Field;
class FieldIterator {
public:
    FieldIterator();
    void entry();
    void next();
    bool isEnd() const;
    Cell* getElem() const;
private:
    std::pair<int, int> position;
    Field* field;
};
