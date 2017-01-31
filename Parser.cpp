#include "Parser.hpp"
#include "OperandFactory.hpp"
#include "Expression.hpp"
#include "Exceptions.hpp"

static void foo(int) {}

Expression *Parser::parse(Operator const *op, std::vector<eOperandType> const& types, std::vector<std::string const *> const& values) const
{
	static const auto factory = new OperandFactory();
	auto operands = new std::vector<IOperand const *>();

	if (types.size() != op->_param_n)
		throw new OperandsMismatchException(op->name, op->_param_n, types.size());
	for (size_t i = 0; i < types.size(); i++)
	{
		operands->push_back(factory->createOperand(types[i], *values[i]));
	}
	return new Expression(*op, operands);
}
