#include "Operators.hpp"

Mod::Mod(void) : Operator(0, 2, "mod") { }

void Mod::execute(VM &vm, std::vector<IOperand const*> const& operands) const
{
	Operator::execute(vm, operands);

	auto &a = *vm.stack.front();
	vm.stack.pop_front();
	auto &b = *vm.stack.front();
	vm.stack.pop_front();
	vm.stack.push_front(a % b);
}
