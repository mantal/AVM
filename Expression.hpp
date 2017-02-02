#pragma once

#include "IOperand.hpp"
#include "Operator.hpp"
#include "VM.hpp"
#include <vector>

class Expression
{
public:

	Expression(Operator const& op, std::vector<IOperand const*> const *operands);

	void execute(VM &vm) const;

	Operator const& op;
	std::vector<IOperand const*> const *operands;

	virtual ~Expression(void) { }

private:

	Expression& operator=(Operator const&);
	Expression(void);
	Expression(Expression const&);
};
