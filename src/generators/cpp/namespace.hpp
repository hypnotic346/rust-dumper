#pragma once

#include <vector>
#include <format>

class cppgen::codeblock;
class cppgen::field_base;

namespace cppgen
{
    class Namespace
    {
    public:
        Namespace(const std::string& name) : m_name{ name } {}

        void init(bool wrap_braces = false)      
        {
            parent_->indent();

            parent_->push_back("namespace ");
            parent_->push_back(m_name);

            if (wrap_braces)
            {
                parent_->break_line();
            }
            else
            {
                parent_->push_back(" ");
            }

            parent_->indent();

            parent_->push_back("{");
            parent_->break_line();
            parent_->m_indentation++;  
        }

        void end()
        {
            std::size_t it{ 0u };

            for (const auto& field : m_fields)
            {
                cppgen::comment *comment = dynamic_cast<cppgen::comment*>(field.get());

                if (comment != nullptr)
                {
                    if (comment->m_next_line)
                    {
                        parent_->indent();
                        field->create(this);
                        parent_->break_line();
                    }
                    else
                    {
                        parent_->push_back(" ");
                        field->create(this);

                        if (it != m_fields.size() - 1)
                            parent_->break_line();
                    }
                }
                else
                {
                    parent_->indent();
                    field->create(this);

                    bool next_is_inline_comment = false;

                    if (it + 1 < m_fields.size())
                    {
                        auto* next_comment = dynamic_cast<cppgen::comment*>(m_fields[it + 1].get());

                        if (next_comment != nullptr && !next_comment->m_next_line)
                            next_is_inline_comment = true;
                    }

                    if (it != m_fields.size() - 1 && !next_is_inline_comment)
                        parent_->break_line();
                }

                ++it;
            }

            parent_->m_indentation--;
            parent_->break_line();
            parent_->indent();
            parent_->push_back("}");
            parent_->break_line();
            parent_->break_line();
        }

        void set_parent(std::shared_ptr<codeblock> block) { parent_ = block; }

        codeblock& get_block() { return *parent_; }

        template<typename T>
        void add_member(const std::string& name, const e_field_type& type, const T val, bool is_hex = false)
        {
            std::shared_ptr<cppgen::field<T>> field_instance = std::make_shared<cppgen::field<T>>(name, type, is_hex);
            field_instance->m_val = val;
            m_fields.emplace_back(std::move(field_instance));
        }

        void add_comment(const std::string &msg, bool next_line = false)
        {
            std::shared_ptr<cppgen::comment> comment = std::make_shared<cppgen::comment>();
            comment->set(msg);
            comment->m_next_line = next_line;

            m_fields.emplace_back(std::move(comment));
        }

        std::vector<std::shared_ptr<cppgen::field_base>> m_fields{};
        std::string m_name{ "" };

    protected:
        std::shared_ptr<codeblock> parent_{ nullptr };
    };

    inline std::shared_ptr<cppgen::Namespace> codeblock::add_namespace(const std::string& name, bool should_wrap)
    {
        std::shared_ptr<cppgen::Namespace> object = std::make_shared<cppgen::Namespace>(name);
        object->set_parent(shared_from_this());
        object->init(should_wrap);
        return object;        
    }
}

inline void cppgen::comment::create(void* parent)
{
    auto ns = reinterpret_cast<cppgen::Namespace*>(parent);
    ns->get_block().push_back(std::format("// {}", m_comment_));
}

template<typename T>
inline void cppgen::field<T>::create(void* parent)
{
    std::string fmt = std::format("inline constexpr {} {} = ", this->get_type_str(), this->get_member_name());
    std::string explicit_suffix = get_type_suffix();

    std::string val_str = m_is_hex
        ? std::format("0x{:X}{}", this->get_val(), explicit_suffix)
        : std::format("{}{}", this->get_val(), explicit_suffix);

    fmt.append(val_str);
    fmt.append(";");

    auto ns = reinterpret_cast<cppgen::Namespace*>(parent);
    ns->get_block().push_back(std::move(fmt));
}
