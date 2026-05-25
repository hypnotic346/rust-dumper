#pragma once

namespace il2cpp
{
    using namespace rust::il2cpp_exports;

    struct assembly_t
    {
        Il2CppImage* image;
        std::string name;
    };

    inline Il2CppThread* il2cpp_thread{ nullptr };

    inline void thread_attach()
    {
        Il2CppDomain* domain = il2cpp_domain_get();

        il2cpp_thread = il2cpp_thread_attach(domain);
    }

    inline void thread_detach()
    {
        il2cpp_thread_detach(il2cpp_thread);
    }

	inline std::vector<assembly_t> get_modules()
	{
        std::vector<assembly_t> list{};

        const Il2CppDomain* domain = il2cpp_domain_get();
        if (!domain) return {};

        size_t size{ 0u };
        const Il2CppAssembly** assemblies = il2cpp_domain_get_assemblies(domain, &size);

        for (size_t i = 0; i < size; ++i) 
        {
            const Il2CppAssembly* assembly = assemblies[i];

            if (assembly != nullptr) 
            {
                const char* assembly_name = il2cpp_image_get_name(assembly->image);

                assembly_t image_info{ .image = assembly->image, .name = assembly_name };

                list.push_back(image_info);
            }
        }

        return list;
	}

    inline FieldInfo* get_field_from_field_class(Il2CppClass* base_klass, const std::string& klass_name)
    {
        void* iter = nullptr;
        while (FieldInfo* field = il2cpp_class_get_fields(base_klass, &iter))
        {
            Il2CppClass* field_klass = il2cpp_class_from_type(field->type);
            if (!field_klass) continue;

            const char* name = il2cpp_class_get_name(field_klass);
            const char* fullname = il2cpp_type_get_name(field->type);

            if ((name && klass_name == name) ||
                (fullname && std::string(fullname).find(klass_name) != std::string::npos))
                return field;
        }
        return nullptr;
    }

    inline Il2CppImage* get_image(const std::string& image_name)
    {
        Il2CppImage* image{ nullptr };
        
        auto assemblies_list = get_modules();
        if (assemblies_list.empty()) return image;

        for (const auto& assembly : assemblies_list)
        {
            if (image_name.find(assembly.name) != std::string::npos)
            {
                image = assembly.image;
                break;
            }
        }

        return image;
    }
}