#include "Operators.hpp"

Mul::Mul(void) : Operator(0, 2, "mul") { }

void Mul::execute(VM &vm, std::vector<IOperand const*> const& operands) const
{
	Operator::execute(vm, operands);

	auto &a = *vm.stack.front();
	vm.stack.pop_front();
	auto &b = *vm.stack.front();
	vm.stack.pop_front();
	vm.stack.push_front(a * b);
}
