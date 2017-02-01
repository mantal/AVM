#include "Operators.hpp"

Push::Push(void) : Operator(1, 0, "push") { }

void Push::execute(VM &vm, std::vector<IOperand const*> const &operands) const
{
	Operator::execute(vm, operands);
	vm.stack.push_front(operands[0]);
}
