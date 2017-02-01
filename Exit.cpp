#include "Operators.hpp"

Exit::Exit(void) : Operator(0, 0, "exit") { }

void Exit::execute(VM &vm, std::vector<IOperand const*> const& operands) const
{
	Operator::execute(vm, operands);

	vm.exit = true;
}
