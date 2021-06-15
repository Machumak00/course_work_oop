#pragma once
#include "libraries.h"

class WrongInformationException {
public:
    explicit WrongInformationException(std::string new_error = "Вызвано исключение получения неверной информации для сохранения или загрузки файла.");
    std::string get_error();
private:
    std::string error;
};
