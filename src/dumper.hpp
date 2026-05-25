#pragma once

#include <filesystem>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>

inline std::shared_ptr<spdlog::logger> console = spdlog::stdout_color_mt("logger_out");

namespace rust
{
    inline Il2CppImage* assembly_csharp{ nullptr };
    inline Il2CppThread* il2cpp_thread{ nullptr };

    namespace base_player
    {
        void generate();
    }

    namespace generator
    {
        inline std::stringstream buffer{};

        void begin_namespace(const std::string& name);
        void add_comment(const std::string& comment);
        void add_field_offset(const std::string& field_name, const std::size_t& offset);
        void end_namespace();
        void write_to_buffer(const std::string& b);
        void new_line();

        void show_output()
        {
            std::cout << buffer.str() << std::endl;
        }
    }

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