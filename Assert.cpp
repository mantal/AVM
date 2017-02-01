#include "Operators.hpp"
#include "Exceptions.hpp"

Assert::Assert(void) : Operator(1, 1, "assert") { }

void Assert::execute(VM &vm, std::vector<IOperand const*> const& operands) const
{
	Operator::execute(vm, operands);

	auto &a = *vm.stack.front();
	if (a.toString() != operands[0]->toString())
		throw AssertionFailedException(operands[0]->toString(), a.toString());
}
