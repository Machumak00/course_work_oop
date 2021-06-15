#include "Field.h"
#include "Cell.h"
#include "ScorePointCreator.h"
#include "HealthCreator.h"
#include "BombCreator.h"
#include "Enemy.hpp"
#include "BehaviorScorepoint.h"
#include "BehaviorTeleport.h"
#include "BehaviorDamage.h"

Field::Field(){
    fill_field();
    set_objects();
    set_enemies();
}

Field::~Field() {
    for (int i = 0; i < size; ++i)
        delete[] field_ptr->field[i];
    delete[] field_ptr->field;
}

void Field::set_objects() {
    BombCreator bomb_creator;
    ScorePointCreator scorepoint_creator;
    HealthCreator health_creator;
    field[1][8].set_object(bomb_creator.CreateGameObject());
    field[1][10].set_object(bomb_creator.CreateGameObject());
    field[1][12].set_object(bomb_creator.CreateGameObject());
    field[1][11].set_object(scorepoint_creator.CreateGameObject());
    field[10][1].set_object(scorepoint_creator.CreateGameObject());
    field[13][13].set_object(scorepoint_creator.CreateGameObject());
    field[13][5].set_object(scorepoint_creator.CreateGameObject());
    field[1][0].set_object(health_creator.CreateGameObject());
    field[1][5].set_object(health_creator.CreateGameObject());
}

void Field::set_enemies() {
    field[3][7].set_enemy_damage(new Enemy<BehaviorDamage>);
    field[5][13].set_enemy_scorepoint(new Enemy<BehaviorScorepoint>);
    field[13][8].set_enemy_teleport(new Enemy<BehaviorTeleport>);
}

int Field::get_size() const{
    return size;
}

Cell& Field::get_cell(int x, int y){
    if(x >= size || x < 0 || y >= size || y < 0){
        std::cerr << "Обращение по индексу недопустимо: выход за размеры поля." << std::endl;
        exit(0);
    }
    return field[x][y];
}

Field* Field::get_field(){
    if (field_ptr == nullptr)
        field_ptr = new Field();
    return field_ptr;
}

void Field::delete_field(){
    if (field_ptr != nullptr){
        delete field_ptr;
        field_ptr = nullptr;
    }
}

Field::Field(const Field& other){
    this->field = new Cell*[size];
    for(int i = 0; i<size; i++){
        this->field[i] = new Cell[size];
        for(int j = 0; j<size; j++)
            this->field[i][j] = other.field[i][j];
    }
}

Field::Field(Field&& other){
    this->field = other.field;
    other.field = nullptr;
}

Field& Field::operator=(const Field& other){
    if (&other == this)
        return *this;
    for(int i = 0; i < size; i++)
        delete[] this->field[i];
    delete[] this->field;
    this->field = new Cell*[size];
    for(int i = 0; i < size; i++){
        this->field[i] = new Cell[size];
        for(int j = 0; j < size; j++)
            this->field[i][j] = other.field[i][j];
    }
    return *this;
}

Field& Field::operator=(Field&& other){
    if(this != &other){
        if(field != nullptr){
            for(int i = 0; i < size; i++)
                delete[] field[i];
            delete[] field;
        }
        field = other.field;
        other.field = nullptr;
    }
    return *this;
}

void Field::fill_field(){
    field = new Cell*[size];
    for(size_t i = 0; i < size; ++i){
        field[i] = new Cell[size];
        for (size_t j = 0; j < size; ++j){
            field[i][j].set_position(i, j);
            if (i % 2 == 0)
                if ((j != 0 || i != 0) && (i != size - 1 || j != size - 1) && j % 2 == 0)
                    field[i][j].set_type(Cell::Wall);
            if (i == size - 1 && j == size - 1)
                field[i][j].set_type(Cell::Exit);
            if (i == 0 && j == 0)
                field[i][j].set_type(Cell::Entry);
        }
    }
}

Field* Field::field_ptr = nullptr;
