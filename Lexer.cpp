#include "Lexer.hpp"
#include "Expression.hpp"
#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "Operators.hpp"
#include "Exceptions.hpp"
#include "Parser.hpp"
#include <boost/algorithm/string.hpp>
#include <string>
#include <unordered_map>
#include <regex>

std::string const Lexer::operand_regex = "\\w+\\((-?\\d+([\\.\\,]\\d+)?)\\)";

Lexer::Lexer(void) { }

Expression *Lexer::lex(std::string const& line) const
{
	static auto const noop = new Expression(*get_operator("noop"), new std::vector<IOperand const*>());
	auto const trimmedLine = boost::trim_copy(line.substr(0, line.find(';')));

	if (trimmedLine == "" || trimmedLine.at(0) == ';')
		return noop;

	Parser parser;
	std::vector<std::string> strings;
	boost::split(strings, trimmedLine, boost::is_space());

	auto it = strings.begin();

	auto op = get_operator(*it);
	auto operands_types = new std::vector<eOperandType>();
	auto operands_values = new std::vector<std::string const*>();

	it++;

	for (; it != strings.end(); it++)
	{
		if (it->size() == 0)
			continue ;
		validate_operand_syntax(*it);
		operands_types->push_back(get_operand_type(*it));
		operands_values->push_back(get_operand_value(*it));
	}
	return parser.parse(op, *operands_types, *operands_values);
}

Operator const *Lexer::get_operator(std::string const& op) const
{
	//TODO utiliser le nom qui est dans l'op
	static const std::unordered_map<std::string, Operator *> operators = {
		{ "push", new Push() },
		{ "pop", new Pop() },
		{ "dump", new Dump() },
		{ "assert", new Assert() },
		{ "add", new Add() },
		{ "sub", new Sub() },
		{ "mul", new Mul() },
		{ "div", new Div() },
		{ "mod", new Mod() },
		{ "print", new Print() },
		{ "exit", new Exit() },
		{ "noop", new NoOp() },
	};
	
	if (operators.count(op) == 0)
		throw UnknowOperatorException(op);
	return operators.at(op);
}

eOperandType Lexer::get_operand_type(std::string const& operand) const
{
	static auto const operand_regex = std::regex("(\\w)+");
	static const std::unordered_map<std::string, eOperandType> operands = {
		{ "int8", eOperandType::Int8 },
		{ "int16", eOperandType::Int16 },
		{ "int32", eOperandType::Int32 },
		{ "float", eOperandType::Float },
		{ "double", eOperandType::Double },
	};
	std::smatch match;

	std::regex_search(operand, match, operand_regex);

	auto const o = match[0].str();
	if (operands.count(o) == 0)
		throw UnknowOperandException(o);
	return operands.at(o);
}

std::string const *Lexer::get_operand_value(std::string const& operand) const
{
	auto const operand_regex = std::regex(Lexer::operand_regex);
	std::smatch match;

	std::regex_search(operand, match, operand_regex);
	return (new std::string(match[1].str()));
}

void Lexer::validate_operand_syntax(std::string const& operand) const
{
	auto const operand_regex = std::regex(Lexer::operand_regex);

	if (!std::regex_match(operand, operand_regex))
		throw SyntaxErrorException(operand);
}
