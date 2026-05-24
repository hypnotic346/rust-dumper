#include <pch.hpp>

void gather_modules();
void setup_console_output();

bool init_dumper()
{
	using namespace dumper;

	il2cpp_exports::init();

	return true;
}

#include <thread>
#include <chrono>

int __stdcall DllMain(HMODULE main_mod, unsigned long reason, void* instance)
{
	setup_console_output();
	gather_modules();

	const bool status = init_dumper();

	if (!status)
	{
		spdlog::error("Failed to process dumper");
		return FALSE;
	}

	while (!GetAsyncKeyState(VK_DELETE))
		std::this_thread::sleep_for(std::chrono::microseconds(300));

	fclose(stdout);
	FreeConsole();
	FreeLibraryAndExitThread(main_mod, 0);

	return TRUE;
}

void gather_modules()
{
	std::array<std::string, 3> module_list = { "RustClient.exe", "GameAssembly.dll", "UnityPlayer.dll" };

	// gather the modules we need in order to generate a dump
	for (const auto& name : module_list)
	{
		void* module = GetModuleHandleA(name.c_str());

		while (!module)
		{
			spdlog::info("Waiting for {} to load...", name);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}

		dumper::modules[name] = reinterpret_cast<HMODULE>(module);
	}
}

void setup_console_output()
{
	if (!AllocConsole()) return;

	FILE* fout = nullptr;
	freopen_s(&fout, "CONOUT$", "w", stdout);

	dumper::setup_logger();
}