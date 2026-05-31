#pragma once

#pragma region cppgenerator_dumper
#define DEFINE_FIELD_OFFSET(field_name) \
    FieldInfo* field_name##_offset = nullptr;

#define GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(namespace_name, member, klass_name, name, ...)  \
    member##_offset = il2cpp::get_field_from_field_class(klass, klass_name, __VA_ARGS__);    \
    ADD_FIELD_MEMBER(namespace_name, name, member##_offset->offset);                         \
    ADD_COMMENT(namespace_name, il2cpp_exports::il2cpp_type_get_name(member##_offset->type));

#define GENERATE_FIELD_MEMBER_BY_NAME(namespace_name, member, field_name, name, ...)         \
    member##_offset = il2cpp::get_field_from_name(klass, field_name, __VA_ARGS__);           \
    ADD_FIELD_MEMBER(namespace_name, name, member##_offset->offset);                         \
    ADD_COMMENT(namespace_name, il2cpp_exports::il2cpp_type_get_name(member##_offset->type));

#define BREAK_LINE rust::cpp_codegen->break_line()

#define ADD_COMMENT(namespace_name, msg, ...)          namespace_name##_namespace_gen->add_comment(msg, __VA_ARGS__)
#define BEGIN_NAMESPACE(x)                             auto x##_namespace_gen = rust::cpp_codegen->add_namespace(#x, true)
#define END_NAMESPACE(x)                               x##_namespace_gen->end()
#define ADD_FIELD_MEMBER(namespace_name, name, offset) namespace_name##_namespace_gen->add_member(name, e_field_type::type_u64, offset, true)
#pragma endregion cppgenerator_dumper

#pragma region il2cpp_helper
#define DEFINE_METHOD(name, typedefs)  \
		using name##_t = typedefs;	   \
		inline name##_t name = nullptr;\

#define INIT_METHOD(name) \
	name = reinterpret_cast<name##_t>(GetProcAddress(rust::modules["GameAssembly.dll"], #name))

#define GET_NAMESPACE_CLASS(assembly, namespaze, class_name) rust::il2cpp_exports::il2cpp_class_from_name(assembly, namespaze, class_name)
#define GET_CLASS(class_name) rust::il2cpp_exports::il2cpp_class_from_name(rust::assembly_csharp, "", class_name) // searches for klasses within the Assembly-CSharp image
#pragma endregion il2cpp_helper