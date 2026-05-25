#include <pch.hpp>

using namespace rust;

void dump_offsets()
{
	BEGIN_NAMESPACE("offsets");
	{
		base_player::generate();
	}
	END_NAMESPACE;
}

bool init_dumper()
{
	// init il2cpp runtime routines
	{
		il2cpp_exports::init();
		il2cpp::thread_attach();
	}

	assembly_csharp = il2cpp::get_image("Assembly-CSharp.dll");
	if (!assembly_csharp)
	{
		console->error("Failed to retrieve Assembly-CSharp.dll");
		return false;
	}

	dump_offsets();

#ifdef _DEBUG
	generator::show_output();
#endif

	return true;
}

void gather_modules();
void setup_console_output();

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

		rust::modules[name] = reinterpret_cast<HMODULE>(module);
	}
}

void setup_console_output()
{
	if (!AllocConsole()) return;

	FILE* fout = nullptr;
	freopen_s(&fout, "CONOUT$", "w", stdout);

	rust::setup_logger();
}