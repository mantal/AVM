#include "Operators.hpp"
#include <iostream>

Dump::Dump(void) : Operator(0, 0, "dump") { }

void Dump::execute(VM &vm, std::vector<IOperand const*> const& operands) const
{
	Operator::execute(vm, operands);
	for (auto it : vm.stack)
		std::cout << it->toString() << std::endl;
}
