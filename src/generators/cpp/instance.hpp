#pragma once

#include <memory>
#include <string>
#include <iostream>

namespace cppgen
{
	class Namespace;

    class codeblock : public std::enable_shared_from_this<cppgen::codeblock>
    {
    public:
        codeblock() : m_ss{}, m_indentation{ 0u } {
        };

        friend std::ostream& operator<<(std::ostream& os, const cppgen::codeblock& block)
        {
            os << block.m_ss.str();
            return os;
        }

        std::shared_ptr<cppgen::Namespace> add_namespace(const std::string& name, bool should_wrap = false);

        inline void push_back(const std::string& buf) noexcept { m_ss << buf; }
        inline void break_line() noexcept { m_ss << "\n"; }

        inline void indent() noexcept
        {
            for (size_t i{ 0 }; i < m_indentation; i++)
                m_ss << "\t";
        }

        inline void dump() { std::cout << m_ss.str() << std::endl; }

        std::size_t m_indentation{ 0u };
        std::stringstream m_ss{};
    };
}
