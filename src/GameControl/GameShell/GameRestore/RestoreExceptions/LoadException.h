#pragma once
#include "libraries.h"

class LoadException {
public:
    explicit LoadException(std::string new_error = "Было вызвано исключение загрузки информации из файла.");
    std::string get_error();
private:
    std::string error;
};
