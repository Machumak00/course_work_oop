#pragma once
#include "libraries.h"

class SaveException {
public:
    explicit SaveException(std::string new_error = "Было вызвано исключение сохранения информации в файл.");
    std::string get_error();
private:
    std::string error;
};
