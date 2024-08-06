#include "core/logger.hpp"

#include "chapters/5_surface_normals.h"


int main() {
    logger_init();

    SPDLOG_INFO("Surface Normals");
    chapter5::chapter5_surface_normals();

    return 0;
}

