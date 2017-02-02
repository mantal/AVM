#include "Operators.hpp"
#include "Exceptions.hpp"
#include "Operand.tpp"
#include <iostream>

Print::Print(void) : Operator(0, 1, "print") { }

void Print::execute(VM &vm, std::vector<IOperand const*> const& operands) const
{
	Operator::execute(vm, operands);

	auto &a = *vm.stack.front();
	//vm.stack.pop_front();

	if (a.getType() != eOperandType::Int8)
		throw AssertionFailedException("an int8", "SOMEHTINGELSEFUCKC++");
	std::cout << static_cast<char>(std::stoi(a.toString())) << std::endl;
}
