#include "LogFile.h"

LogFile::LogFile() {
    try {
        output = new std::ofstream;
        if (file_is_empty){
            output->open("../src/GameLogging/log_file.txt");
            file_is_empty = false;
        }
        else
            output->open("../src/GameLogging/log_file.txt", std::ios::app);
        if (!output->is_open())
            throw std::string("Файл не может быть открыт!");
    }
    catch(const std::string& str) {
        std::cerr << str << std::endl;
        clear_memory();
        exit(0);
    }
}

LogFile::~LogFile() {
    output->close();
    clear_memory();
}

void LogFile::add_log(const std::string& new_str) {
    *output << "Номер лога (" << count++ << ") " << "Содержимое лога: <" << new_str << ">" << std::endl;
}

void LogFile::clear_memory() {
    if (output != nullptr)
        delete output;
}

bool LogFile::file_is_empty = true;
int LogFile::count = 1;
