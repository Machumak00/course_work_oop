#pragma once

class Cell;
class Field {
public:
    int get_size() const;
    Cell& get_cell(int x, int y);
    static Field* get_field();
    void delete_field();
private:
    Field();
    ~Field();
    Field(const Field& otherField);
    Field(Field&& otherField);
    Field& operator=(const Field& otherField);
    Field& operator=(Field&& tmpField);
    void fill_field();
    void set_objects();
    void set_enemies();

    Cell** field;
    const int size = 15;
    static Field* field_ptr;
};
