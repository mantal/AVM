#include "VM.hpp"
#include "Expression.hpp"

VM::VM(std::vector<Expression const*> const& expressions_) : expressions(expressions_) { }
VM::VM(void) {}

void VM::run(void)
{
	for (auto it: expressions)
	{
		it->execute(*this);
	}
}

VM::~VM(void) { }
