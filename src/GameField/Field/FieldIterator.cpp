#include "FieldIterator.h"
#include "Field.h"

FieldIterator::FieldIterator(){
    field = Field::get_field();
}

void FieldIterator::entry(){
    position.first = 0;
    position.second = 0;
}

void FieldIterator::next(){
    if (position.first != Field::get_field()->get_size() - 1)
        position.first++;
    else
        if(position.second != Field::get_field()->get_size() - 1){
            position.first = 0;
            position.second++;
        }
}

bool FieldIterator::isEnd() const{
    return position.second == Field::get_field()->get_size() - 1 && position.first == Field::get_field()->get_size() - 1;
}

Cell* FieldIterator::getElem() const {
    return &field->get_cell(position.first, position.second);
}
