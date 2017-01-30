#include "OperandFactory.hpp"
#include "Expression.hpp"
#include "Operator.hpp"
#include "Push.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	const auto factory = new OperandFactory();
	const auto a = factory->createOperand(eOperandType::Int16, argc > 1 ? argv[1] : "17");
	const std::vector<IOperand const*> operands = { a };


	auto push = new Push();
	const std::vector<Expression const *> expressions = {
			new Expression(*push, operands),
			new Expression(*push, operands),
	};

	auto vm = new VM(expressions);
	
	vm->run();

	std::cout << vm->stack[0]->toString() << std::endl;
	std::cout << vm->stack[1]->toString() << std::endl;

	return 0;
}
