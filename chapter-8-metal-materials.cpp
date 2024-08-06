#include "core/logger.hpp"

int main() {
    logger_init();

    SPDLOG_ERROR("AAAAA");

    return 0;
}
