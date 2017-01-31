#pragma once

#include "IOperand.hpp"
#include "VM.hpp"
#include <vector>

class Operator
{
public:
	
	virtual void execute(VM &vm, std::vector<IOperand const*> const &operands) const;

	virtual ~Operator() { }

	size_t getParamNumber(void);

	const size_t _param_n;
	const size_t _stack_param_n;
	const std::string name;

protected:

	Operator(size_t param_n, size_t stack_param_n, char const *name);

private:

	Operator(void);
	Operator(Operator const&);
	Operator& operator=(Operator const&);
};
