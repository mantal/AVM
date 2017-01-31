#pragma once

#include "Expression.hpp"

class Lexer
{
public:

	Expression *lex(std::string const&) const;

	Operator const *get_operator(std::string const& op) const;
	eOperandType get_operand_type(std::string const& operand) const;
	std::string const *get_operand_value(std::string const& operand) const;

	void validate_operand_syntax(std::string const&) const;

private:

	static std::string const value_regex_string;
};
