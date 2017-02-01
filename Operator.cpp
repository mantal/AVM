#include "Operator.hpp"
#include <exception>
#include <string>

Operator::Operator(size_t param_n, size_t stack_param_n, char const *name_) : _param_n(param_n), _stack_param_n(stack_param_n), name(name_) { }

void Operator::execute(VM &vm, std::vector<IOperand const*> const&) const
{
	if (vm.stack.size() < _stack_param_n)
		throw std::out_of_range("Operator " + name + " need " + std::to_string(_stack_param_n) + " values in the stack but " + std::to_string(vm.stack.size()) + " were found");
}

size_t Operator::getParamNumber(void) { return _param_n; }
