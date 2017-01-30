#pragma once

#include "IOperand.hpp"
#include "VM.hpp"
#include <vector>

class Operator
{
public:
	
	Operator(VM& vm, size_t param_n, size_t stack_param_n);

	virtual void execute(std::vector<IOperand const&> const& values) const;

	virtual ~Operator() { }

	size_t getParamNumber(void);

	const size_t _param_n;
	const size_t _stack_param_n;

private:
	VM& _vm;

	Operator(void);
	Operator(Operator const&);
	Operator& operator=(Operator const&);
};
