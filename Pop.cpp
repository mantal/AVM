#include "Operators.hpp"

Pop::Pop(void) : Operator(0, 1, "pop") { }

void Pop::execute(VM &vm, std::vector<IOperand const*> const& operands) const
{
	Operator::execute(vm, operands);
	vm.stack.pop_front();
}
