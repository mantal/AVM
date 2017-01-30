#include "Operator.hpp"
#include <exception>//TODO FAIRE UN TRUC SPE

Operator(VM& vm, size_t param_n, size_t stack_param_n) : _vm(vm), _param_n(param_n), _stack_param_n(stack_param_n) { }

void Operator::execute(std::vector<IOperand const&> const&) const
{
	if (_vm.stack.size() < _stack_param_n)
		throw new std::exception();
}


size_t getParamNumber(void) { return _param_n; }
