#include "core/logger.hpp"

#include "chapters/6_antialiasing.h"


int main() {
    logger_init();

    SPDLOG_INFO("Antialiasing");
    chapter6::chapter6_antialiasing();

    return 0;
}
