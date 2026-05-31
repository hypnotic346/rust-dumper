#pragma once

class Il2CppClass;

namespace memory
{
    [[noexcept]] inline std::uintptr_t find_field_ptr(const Il2CppClass *target)
    {
        auto* module = reinterpret_cast<std::uint8_t*>(rust::modules["GameAssembly.dll"]);
        if (!module) return 0;

        IMAGE_DOS_HEADER* dos = reinterpret_cast<IMAGE_DOS_HEADER*>(module);
        IMAGE_NT_HEADERS* nt = reinterpret_cast<IMAGE_NT_HEADERS*>(module + dos->e_lfanew);
        auto section = IMAGE_FIRST_SECTION(nt);

        for (std::uint16_t i = 0; i < nt->FileHeader.NumberOfSections; i++, section++)
        {
            if (std::strncmp(reinterpret_cast<char*>(section->Name), ".data", 5) != 0)
                continue;

            auto section_start = reinterpret_cast<std::uintptr_t>(module) + section->VirtualAddress;
            auto section_end = section_start + section->Misc.VirtualSize;

            for (auto addr = section_start; addr < section_end - sizeof(std::uintptr_t); addr += sizeof(std::uintptr_t))
            {
                if (*reinterpret_cast<std::uintptr_t*>(addr) == reinterpret_cast<std::uintptr_t>(target))
                    return addr;
            }
        }

        return 0;
    }
}