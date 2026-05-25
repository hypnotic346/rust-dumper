#include <pch.hpp>

#define BREAK_LINE rust::generator::new_line()

#define GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_klass, klass_name, name)      \
    current_field = il2cpp::get_field_from_field_class(base_klass, klass_name); \
    DEFINE_FIELD(name, current_field->offset);                                  \
    ADD_COMMENT(il2cpp_exports::il2cpp_type_get_name(current_field->type));     \
    BREAK_LINE;

namespace rust::base_player
{
    void generate()
    {
        Il2CppClass *klass = GET_CLASS("BasePlayer");
        if (!klass) return;

        {
            FieldInfo *current_field{ nullptr };

            BEGIN_NAMESPACE("base_player");

            GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(klass, "PlayerEyes", "eyes");
            GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(klass, "PlayerInventory", "inventory");
            GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(klass, "PlayerModel", "player_model");
            GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(klass, "PlayerInput", "input");
            GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(klass, "BaseMovement", "movement");
            GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(klass, "BaseCollision", "collision");
            GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(klass, "PlayerFlags", "player_flags");

            END_NAMESPACE;
        }
    }
}

namespace rust::generator
{
	void clear()
	{
		buffer.clear();
	}

    bool should_add_new_line{ false };
    int depth{ 0 };

    void new_line()
    {
        buffer << '\n';
    }

    void indent()
    {
        for (int i = 0; i < depth; ++i)
            buffer << '\t';
    }

    void begin_namespace(const std::string& name)
    {
        indent();
        buffer << "namespace " << name;
        new_line();
        indent();
        buffer << "{";
        new_line();
        ++depth;
    }

    void add_comment(const std::string &comment)
    {
        indent();
        buffer << "// " << comment;
    }

    void add_field_offset(const std::string &field_name, const std::size_t& offset)
    {
        indent();
        buffer << "static constexpr std::size_t " << field_name << " = 0x" << std::hex << std::uppercase << offset << ";";
    }

    void end_namespace()
    {
        --depth;
        indent();
        buffer << "}";
        new_line();

        if (depth == 0) new_line();
    }

	void write_to_buffer(const std::string& b)
	{
		buffer << b;
	}
}