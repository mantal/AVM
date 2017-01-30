#pragma once

#include "Operator.hpp"

class Add : public Operator
{
public:

	Add(void);

	virtual void execute(VM &vm, std::vector<IOperand const*> const& operands) const;
};
