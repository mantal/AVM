#include "Operator.hpp"
#include <exception>
#include <boost/format.hpp>

Operator::Operator(size_t param_n, size_t stack_param_n, char const *name) : _param_n(param_n), _stack_param_n(stack_param_n), name(name) { }

void Operator::execute(VM &vm, std::vector<IOperand const*> const&) const
{
	if (vm.stack.size() < _stack_param_n)
	{
		throw new std::out_of_range((boost::format("Operator %1% need %2% in the stack\n") % name % vm.stack.size()).str().c_str());
	}
}

size_t Operator::getParamNumber(void) { return _param_n; }
