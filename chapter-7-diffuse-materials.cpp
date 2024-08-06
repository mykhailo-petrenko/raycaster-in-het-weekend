#include "core/logger.hpp"

#include "chapters/7_diffuse_materials.h"

int main() {
    logger_init();

    SPDLOG_INFO("Diffuse");
    chapter7::chapter7_diffuse_materials();

    return 0;
}
