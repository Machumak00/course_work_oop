#include "SpawnElementObserver.h"
#include "LogFile.h"

void SpawnElementObserver::update(const std::string& new_str) {
    LogFile logFile;
    logFile.add_log("На поле был создан элемент: " + new_str);
    std::cout << "На поле был создан элемент: " + new_str << std::endl;
}
