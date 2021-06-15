#pragma once

#include "libraries.h"

class LogFile {
public:
    LogFile();
    ~LogFile();
    void add_log(const std::string& new_str);
private:
    void clear_memory();
    static bool file_is_empty;
    static int count;
    std::ofstream *output;
};
