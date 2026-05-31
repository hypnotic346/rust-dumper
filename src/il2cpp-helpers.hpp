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

    inline FieldInfo* get_fields_by_comparison(Il2CppClass* klass, std::function<bool(FieldInfo*)> fn)
    {
        FieldInfo* next = nullptr;
        void* iter = nullptr;

        while (FieldInfo* field = il2cpp_class_get_fields(klass, &iter))
        {
            if (!fn(field)) continue;

            next = field;
            break;
        }

        return next;
    }

    inline FieldInfo* get_field_from_name(Il2CppClass* klass, const std::string& field_name)
    {
        FieldInfo* ret = get_fields_by_comparison(klass, [&](FieldInfo* field) -> bool
        {
             return field->name == field_name;
        });

        return ret;
    }
    
    inline const Il2CppClass *get_inner_static_class(Il2CppClass* klass)
    {
        if (!klass || !il2cpp_class_get_type(klass)) return nullptr;

        void* iter = nullptr;
        while (Il2CppClass* _klass = il2cpp_class_get_nested_types(klass, &iter))
        {
            void* method_iter = nullptr;
            int method_count = 0;
            while (il2cpp_class_get_methods(_klass, &method_iter))
                method_count++;

            if (method_count != 1) continue;
            if (!il2cpp_class_get_method_from_name(_klass, ".cctor", -1)) continue;

            void* field_iter = nullptr;
            bool all_static = true;
            while (FieldInfo* field = il2cpp_class_get_fields(_klass, &field_iter))
            {
                if (!(il2cpp_field_get_flags(field) & FIELD_ATTRIBUTE_STATIC))
                {
                    all_static = false;
                    break;
                }
            }

            if (!all_static) continue;

            return _klass;
        }

        return nullptr;
    }

    inline FieldInfo* get_field_from_field_class(Il2CppClass* base_klass, const std::string& class_name, std::uint32_t required_attrs = 0, const char* required_type = nullptr)
    {
        return get_fields_by_comparison(base_klass, [&](FieldInfo* field) -> bool 
        {
            Il2CppClass* klass = il2cpp_class_from_type(field->type);
            if (!klass) return false;

            const char *klass_name = il2cpp_class_get_name(klass);
            const char *field_type_name = il2cpp_type_get_name(field->type);

            if (required_attrs != 0)
            {
                std::uint32_t attrs = il2cpp_field_get_flags(field);
                if ((attrs & required_attrs) != required_attrs)
                    return false;
            }

            bool matched = (klass_name && class_name == klass_name) || (field_type_name && std::string(field_type_name).find(class_name) != std::string::npos);

            return matched;
        });
    }

    inline Il2CppImage* get_image(const std::string& image_name)
    {
        Il2CppImage* image{ nullptr };
        
        auto assemblies_list = get_modules();
        if (assemblies_list.empty()) return image;

        for (const auto& assembly : assemblies_list)
        {
            if (assembly.name == image_name)
            {
                image = assembly.image;
                break;
            }
        }

        return image;
    }
}