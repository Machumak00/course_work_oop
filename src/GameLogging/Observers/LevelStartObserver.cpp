#include "LevelStartObserver.h"
#include "LogFile.h"

void LevelStartObserver::update(const std::string& new_str) {
    LogFile logFile;
    logFile.add_log(new_str);
    std::cout << new_str << std::endl;
}
