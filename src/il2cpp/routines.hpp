#pragma once
#include <any>
#include <macros.hpp>

namespace dumper::il2cpp_exports
{
    DEFINE_METHOD(il2cpp_init, void(*)(const char*))
    DEFINE_METHOD(il2cpp_shutdown, void(*)())
    DEFINE_METHOD(il2cpp_domain_get, Il2CppDomain* (*)())
    DEFINE_METHOD(il2cpp_domain_get_assemblies, const Il2CppAssembly** (*)(const Il2CppDomain*, size_t*))
    DEFINE_METHOD(il2cpp_thread_attach, Il2CppThread* (*)(Il2CppDomain*))
    DEFINE_METHOD(il2cpp_thread_detach, void(*)(Il2CppThread*))
    DEFINE_METHOD(il2cpp_assembly_get_image, const Il2CppImage* (*)(const Il2CppAssembly*))
    DEFINE_METHOD(il2cpp_image_get_name, const char* (*)(const Il2CppImage*))
    DEFINE_METHOD(il2cpp_class_from_name, Il2CppClass* (*)(const Il2CppImage*, const char*, const char*))
    DEFINE_METHOD(il2cpp_class_get_name, const char* (*)(const Il2CppClass*))
    DEFINE_METHOD(il2cpp_class_get_namespace, const char* (*)(const Il2CppClass*))
    DEFINE_METHOD(il2cpp_class_get_type, const Il2CppType* (*)(Il2CppClass*))
    DEFINE_METHOD(il2cpp_class_get_fields, FieldInfo* (*)(Il2CppClass*, void**))
    DEFINE_METHOD(il2cpp_class_get_methods, const MethodInfo* (*)(Il2CppClass*, void**))
    DEFINE_METHOD(il2cpp_class_get_properties, const PropertyInfo* (*)(Il2CppClass*, void**))
    DEFINE_METHOD(il2cpp_class_get_method_from_name, const MethodInfo* (*)(Il2CppClass*, const char*, int))
    DEFINE_METHOD(il2cpp_class_get_field_from_name, FieldInfo* (*)(Il2CppClass*, const char*))
    DEFINE_METHOD(il2cpp_method_get_name, const char* (*)(const MethodInfo*))
    DEFINE_METHOD(il2cpp_method_get_param_count, uint32_t(*)(const MethodInfo*))
    DEFINE_METHOD(il2cpp_field_get_name, const char* (*)(FieldInfo*))
    DEFINE_METHOD(il2cpp_field_get_type, const Il2CppType* (*)(FieldInfo*))
    DEFINE_METHOD(il2cpp_field_get_offset, uint32_t(*)(FieldInfo*))
    DEFINE_METHOD(il2cpp_field_get_value, void(*)(Il2CppObject*, FieldInfo*, void*))
    DEFINE_METHOD(il2cpp_field_set_value, void(*)(Il2CppObject*, FieldInfo*, void*))
    DEFINE_METHOD(il2cpp_field_static_get_value, void(*)(FieldInfo*, void*))
    DEFINE_METHOD(il2cpp_field_static_set_value, void(*)(FieldInfo*, void*))
    DEFINE_METHOD(il2cpp_type_get_name, const char* (*)(const Il2CppType*))
    DEFINE_METHOD(il2cpp_type_get_object, Il2CppObject* (*)(const Il2CppType*))
    DEFINE_METHOD(il2cpp_property_get_name, const char* (*)(const PropertyInfo*))
    DEFINE_METHOD(il2cpp_object_new, Il2CppObject* (*)(const Il2CppClass*))
    DEFINE_METHOD(il2cpp_object_get_class, Il2CppClass* (*)(Il2CppObject*))
    DEFINE_METHOD(il2cpp_object_unbox, void* (*)(Il2CppObject*))
    DEFINE_METHOD(il2cpp_runtime_invoke, Il2CppObject* (*)(const MethodInfo*, void*, void**, Il2CppException**))
    DEFINE_METHOD(il2cpp_resolve_icall, void* (*)(const char*))
    DEFINE_METHOD(il2cpp_string_new, Il2CppString* (*)(const char*))
    DEFINE_METHOD(il2cpp_array_new, Il2CppArray* (*)(Il2CppClass*, il2cpp_array_size_t))
    DEFINE_METHOD(il2cpp_array_length, il2cpp_array_size_t(*)(Il2CppArray*))
    DEFINE_METHOD(il2cpp_value_box, Il2CppObject* (*)(Il2CppClass*, void*))
    DEFINE_METHOD(il2cpp_gc_disable, void(*)())
    DEFINE_METHOD(il2cpp_gc_enable, void(*)())

    inline void init()
    {
        INIT_METHOD(il2cpp_init);
        INIT_METHOD(il2cpp_shutdown);
        INIT_METHOD(il2cpp_domain_get);
        INIT_METHOD(il2cpp_domain_get_assemblies);
        INIT_METHOD(il2cpp_thread_attach);
        INIT_METHOD(il2cpp_thread_detach);
        INIT_METHOD(il2cpp_assembly_get_image);
        INIT_METHOD(il2cpp_image_get_name);
        INIT_METHOD(il2cpp_class_from_name);
        INIT_METHOD(il2cpp_class_get_name);
        INIT_METHOD(il2cpp_class_get_namespace);
        INIT_METHOD(il2cpp_class_get_type);
        INIT_METHOD(il2cpp_class_get_fields);
        INIT_METHOD(il2cpp_class_get_methods);
        INIT_METHOD(il2cpp_class_get_properties);
        INIT_METHOD(il2cpp_class_get_method_from_name);
        INIT_METHOD(il2cpp_class_get_field_from_name);
        INIT_METHOD(il2cpp_method_get_name);
        INIT_METHOD(il2cpp_method_get_param_count);
        INIT_METHOD(il2cpp_field_get_name);
        INIT_METHOD(il2cpp_field_get_type);
        INIT_METHOD(il2cpp_field_get_offset);
        INIT_METHOD(il2cpp_field_get_value);
        INIT_METHOD(il2cpp_field_set_value);
        INIT_METHOD(il2cpp_field_static_get_value);
        INIT_METHOD(il2cpp_field_static_set_value);
        INIT_METHOD(il2cpp_type_get_name);
        INIT_METHOD(il2cpp_type_get_object);
        INIT_METHOD(il2cpp_property_get_name);
        INIT_METHOD(il2cpp_object_new);
        INIT_METHOD(il2cpp_object_get_class);
        INIT_METHOD(il2cpp_object_unbox);
        INIT_METHOD(il2cpp_runtime_invoke);
        INIT_METHOD(il2cpp_resolve_icall);
        INIT_METHOD(il2cpp_string_new);
        INIT_METHOD(il2cpp_array_new);
        INIT_METHOD(il2cpp_array_length);
        INIT_METHOD(il2cpp_value_box);
        INIT_METHOD(il2cpp_gc_disable);
        INIT_METHOD(il2cpp_gc_enable);

        console->debug("Initialized il2cpp methods.");
    }
}