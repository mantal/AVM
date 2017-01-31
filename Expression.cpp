#include "Expression.hpp"

Expression::Expression(Operator const& pop, std::vector<IOperand const*> const *poperands) : op(pop), operands(poperands) { }

void Expression::execute(VM &vm) const
{
	op.execute(vm, *operands);
}
