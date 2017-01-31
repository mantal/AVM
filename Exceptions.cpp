#include "Exceptions.hpp"
#include <boost/format.hpp>

UnknowOperatorException::UnknowOperatorException(std::string const& op) : std::runtime_error((boost::format("Unknow operator: %1%") % op).str()) {}
UnknowOperandException::UnknowOperandException(std::string const& op) : std::runtime_error((boost::format("Unknow operand: %1%") % op).str()) {}//TODO pas boost
SyntaxErrorException::SyntaxErrorException(std::string const& op) : std::runtime_error("Syntax error: " + op) {}
OperandsMismatchException::OperandsMismatchException(std::string const& op, size_t expected, size_t found)
		: std::runtime_error("Operator " + op + " expected " + std::to_string(expected) + " operands but " + std::to_string(found) + " were found") {}
