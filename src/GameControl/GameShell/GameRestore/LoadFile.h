#pragma once
#include "libraries.h"

class Snapshot;
class LoadFile {
public:
    LoadFile();
    ~LoadFile();
    Snapshot load_file();
private:
    std::ifstream* file;
    std::vector<int> from_str_to_int(const std::string& str, const std::string& delim = " ");
};
