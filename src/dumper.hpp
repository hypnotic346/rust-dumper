#pragma once

#include <filesystem>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>

inline std::shared_ptr<spdlog::logger> console = spdlog::stdout_color_mt("logger_out");

#define DEFINE_CLASS(namespace_name)              \
    namespace namespace_name { void generate(); } \

namespace rust
{
    inline Il2CppImage *assembly_csharp = nullptr;
    inline Il2CppThread *il2cpp_thread = nullptr;

    inline std::shared_ptr<cppgen::codeblock> cpp_codegen = nullptr;

    DEFINE_CLASS(base_networkable);
    DEFINE_CLASS(main_camera);
    DEFINE_CLASS(base_player);
    DEFINE_CLASS(base_entity);

	inline void setup_logger()
	{
        auto cwd = std::filesystem::current_path().string();
        auto logger_name = "dumper";
        auto logger_file = "output.log";
        auto log_level = spdlog::level::debug;

        std::vector<spdlog::sink_ptr> sinks
        {
            std::make_shared<spdlog::sinks::stdout_color_sink_mt>(),
            std::make_shared<spdlog::sinks::basic_file_sink_mt>(logger_file),
        };

        console = std::make_shared<spdlog::logger>(logger_name, begin(sinks), end(sinks));
        console->set_level(spdlog::level::info);

        spdlog::register_logger(console);
        spdlog::set_default_logger(console);
        spdlog::set_level(log_level);
        spdlog::flush_every(std::chrono::milliseconds(500));
	}
}