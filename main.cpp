#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "chapters/3_ray_and_background.h"


int main() {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    const std::string pattern_default = "%Y-%m-%d %T.%e  %n %-8l [%-8t] %v |%! %g:%#";
    console_sink->set_pattern( pattern_default );
    console_sink->set_level(spdlog::level::trace);
    spdlog::sinks_init_list sink_list = { console_sink };
    spdlog::set_default_logger( std::make_shared<spdlog::logger>( "main", sink_list ) );
    spdlog::default_logger()->set_level( spdlog::level::trace );

    auto logger = spdlog::default_logger();

    SPDLOG_INFO("Hello Info {}", 12);
    chapter3_ray_and_background();

    return 0;
}
