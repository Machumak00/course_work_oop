#pragma once
#include <fstream>
#include <iostream>

class Snapshot;
class SaveFile {
public:
    SaveFile();
    ~SaveFile();
    void save_file(Snapshot snapshot);
private:
    std::ofstream* file;
};
