#include <iostream>
#include "logger.h"
#include "hype.h"

logger&& hypLogger = get_logger();
int main() {

    std::cout << "Hello, World!" << std::endl;
    hypLogger.writer<Console>("Console Logging");
    hyper_connection();
    hypLogger.writer<File>("File Logging");
    std::cout << hypLogger.getData<Console>()<<std::endl;
    std::cout << hypLogger.getData<File>()<<std::endl;
    std::cout << hypLogger.getData<QTGUI>()<<std::endl;
    return 0;
}
