#include "core/logger.hpp"
#include "chapters/chapter8_metal_material.hpp"

int main() {
    logger_init();

    SPDLOG_INFO("Metal Material");

    chapter8::chapter8_metal_material("artifacts/chapter8.bmp");

    return 0;
}
