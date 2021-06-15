#include "WrongInformationException.h"

WrongInformationException::WrongInformationException(std::string new_error) {
    error = std::move(new_error);
}

std::string WrongInformationException::get_error() {
    return error;
}
