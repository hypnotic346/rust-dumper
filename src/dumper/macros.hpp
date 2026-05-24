#pragma once

#define as_v(T, ...) std::any_cast<T>(__VA_ARGS__)

#define DEFINE_METHOD(name, typedefs)  \
		using name##_t = typedefs;	   \
		inline name##_t name = nullptr;\

#define INIT_METHOD(name) \
	name = reinterpret_cast<name##_t>(GetProcAddress(dumper::modules["GameAssembly.dll"], #name))
