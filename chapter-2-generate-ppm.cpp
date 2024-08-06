#include "core/logger.hpp"
#include "chapters/2_generate-ppm.h"


int main() {
    logger_init();

    SPDLOG_INFO("Chapter 2: Generate PPM");
    generate_test_ppm();

    return 0;
}
