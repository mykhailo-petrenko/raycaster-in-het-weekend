#include "core/logger.hpp"

#include "chapters/4_ray_and_sphere.h"


int main() {
    logger_init();

    SPDLOG_INFO("Ray and Sphere");
    chapter4_ray_and_sphere();

    return 0;
}
