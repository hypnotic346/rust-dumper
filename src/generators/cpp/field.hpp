#pragma once

#include <unordered_map>
#include <format>

enum class e_field_type : std::uint8_t
{
	invalid = -1,
	type_u8,
	type_u16,
	type_u32,
	type_u64,
	type_boolean,
	type_double,
	type_float,
	type_int
};

namespace cppgen
{
	class Namespace;

	inline std::unordered_map<e_field_type, std::string> type_to_str =
	{
		{ e_field_type::type_u8,      "std::uint8_t"  },
		{ e_field_type::type_u16,     "std::uint16_t" },
		{ e_field_type::type_u64,     "std::size_t"   },
		{ e_field_type::type_boolean, "bool"          },
		{ e_field_type::type_double,  "double"        },
		{ e_field_type::type_float,   "float"         },
		{ e_field_type::type_int,     "int"           },
	};

	inline std::string field_type_to_str(const e_field_type& type)
	{
		std::string ret{};

		if (const auto found = type_to_str.find(type); found != type_to_str.end())
			ret = found->second;

		return ret;
	}

	struct field_base
	{
		//field_base() = default;

		field_base(const std::string& name, const e_field_type& type)
			: m_name{ name }, m_type{ type } 
		{
		}

		virtual void create(void* parent) = 0;
		virtual ~field_base() = default;

		std::string m_name{};
		e_field_type m_type{};
	};

	struct comment : public cppgen::field_base
	{
	public:
		comment() : field_base{ "", e_field_type::invalid } {}

		void create(void* parent) override;
		void set(const std::string& msg) { m_comment_ = msg; }

		inline std::string get() const { return m_comment_; }

		bool m_next_line{ false };

	protected:
		std::string m_comment_;
	};

	template<typename T>
	class field : public cppgen::field_base
	{
	public:
		field(const std::string& member_name, const e_field_type& type, bool hex = false) : field_base{ member_name, type }, m_member_name{ member_name }, m_is_hex{ hex }
		{
			set_type(type);
		}

		std::string get_type_suffix() const
		{
			switch (m_type)
			{
			case e_field_type::type_u64:
			case e_field_type::type_u16:
				return "u";
			case e_field_type::type_u32:
				return "ul"; 
				break;
			case e_field_type::type_float:
				return ".f";
			}

			return "";
		}

		void create(void* parent) override;

		inline T get_val() { return m_val; }

		inline std::string get_member_name() { return m_member_name; }

		inline e_field_type get_type() { return m_type; }

		inline std::string get_type_str() { return m_type_str; }

		void set_member_name(const std::string& name) { m_member_name = name; }

		void set_type(const e_field_type& type)
		{
			m_type = type;
			m_type_str = field_type_to_str(type);
		}

		T m_val{};

	protected:
		std::string m_type_str{ "" }, m_member_name{};
		e_field_type m_type{};
		bool m_is_hex{ false };
	};
}
