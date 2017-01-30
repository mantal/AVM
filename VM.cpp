#include "VM.hpp"
#include "Expression.hpp"

VM::VM(std::vector<Expression const*> const& expressions) : _expressions(expressions) { }

void VM::run(void)
{
	for (auto it: _expressions)
	{
		it->execute(*this);
	}
}
