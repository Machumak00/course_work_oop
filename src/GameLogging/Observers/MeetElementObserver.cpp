#include "MeetElementObserver.h"
#include "LogFile.h"

void MeetElementObserver::update(const std::string& new_str) {
    LogFile logFile;
    logFile.add_log("Игрок встретил элемент: " + new_str);
    std::cout << "Игрок встретил элемент: " + new_str << std::endl;
}
