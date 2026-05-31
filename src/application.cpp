#include <pch.hpp>

using namespace rust;

void dump_offsets()
{
	BEGIN_NAMESPACE(offsets);
	{
		ADD_FIELD_MEMBER(offsets, "static_fields", 0xb8);	
		
		base_player::generate();
		base_networkable::generate();
		base_entity::generate();
		main_camera::generate();
	}
	END_NAMESPACE(offsets);
}

bool init_dumper()
{
	// init il2cpp runtime routines
	{
		il2cpp_exports::init();
		console->debug("Initialized IL2CPP routines");

		il2cpp::thread_attach();
		console->debug("Thread attached to VM domain");
	}

	assembly_csharp = il2cpp::get_image("Assembly-CSharp.dll");
	if (!assembly_csharp)
	{
		throw std::runtime_error("Failed to retrieve module.");
		return false;
	}

	rust::cpp_codegen = std::make_shared<cppgen::codeblock>();

	dump_offsets();

#ifdef _DEBUG
	rust::cpp_codegen->dump();
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