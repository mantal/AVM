#include "Exceptions.hpp"

UnknowOperatorException::UnknowOperatorException(std::string const& op)
		: std::runtime_error("Unknow operator: " + op) {}

UnknowOperandException::UnknowOperandException(std::string const& op)
		: std::runtime_error("Unknow operand: " +  op) {}

SyntaxErrorException::SyntaxErrorException(std::string const& op)
		: std::runtime_error("Syntax error: " + op) {}

OperandsMismatchException::OperandsMismatchException(std::string const& op, size_t expected, size_t found)
		: std::runtime_error("Operator " + op + " expected " + std::to_string(expected) + " operands but " + std::to_string(found) + " were found") {}
