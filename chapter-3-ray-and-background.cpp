#include "core/logger.hpp"

#include "chapters/3_ray_and_background.h"


int main() {
    logger_init();

    SPDLOG_INFO("Ray and Background");
    chapter3_ray_and_background();

    return 0;
}
