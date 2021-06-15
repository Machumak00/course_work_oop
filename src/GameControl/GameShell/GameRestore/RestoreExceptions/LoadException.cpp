#include "LoadException.h"

LoadException::LoadException(std::string new_error) {
    error = std::move(new_error);
}

std::string LoadException::get_error() {
    return error;
}
