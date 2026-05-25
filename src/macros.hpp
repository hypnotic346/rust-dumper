#pragma once

#define as_v(T, ...) std::any_cast<T>(__VA_ARGS__)

#define DEFINE_METHOD(name, typedefs)  \
		using name##_t = typedefs;	   \
		inline name##_t name = nullptr;\

#define INIT_METHOD(name) \
	name = reinterpret_cast<name##_t>(GetProcAddress(rust::modules["GameAssembly.dll"], #name))

#define ADD_COMMENT(msg) rust::generator::add_comment(msg)
#define BEGIN_NAMESPACE(x) rust::generator::begin_namespace(x)
#define END_NAMESPACE rust::generator::end_namespace()
#define DEFINE_FIELD(name, offset) rust::generator::add_field_offset(name, offset)

#define GET_NAMESPACE_CLASS(assembly, namespaze, class_name) rust::il2cpp_exports::il2cpp_class_from_name(assembly, namespaze, class_name)
#define GET_CLASS(class_name) rust::il2cpp_exports::il2cpp_class_from_name(rust::assembly_csharp, "", class_name) // searches for klasses within the Assembly-CSharp image