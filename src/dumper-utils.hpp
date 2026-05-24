#pragma once

#include <filesystem>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

inline std::shared_ptr<spdlog::logger> console = spdlog::stdout_color_mt("logger_out");

namespace dumper
{
	inline std::unordered_map<std::string, HMODULE> modules{};

	inline void setup_logger()
	{
        auto cwd = std::filesystem::current_path().string();
        auto logger_name = "dumper";
        auto logger_file = "output.log";
        auto log_level = spdlog::level::debug;

        std::vector<spdlog::sink_ptr> sinks{
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