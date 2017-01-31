#pragma once

#include "Operator.hpp"

class Push : public Operator
{
public:

	Push(void);

	virtual void execute(VM &vm, std::vector<IOperand const*> const &operands) const;
};
