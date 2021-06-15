#include "SaveException.h"

SaveException::SaveException(std::string new_error) {
    error = std::move(new_error);
}

std::string SaveException::get_error() {
    return error;
}
