#pragma once

#include "IOperand.hpp"
#include "Operator.hpp"
#include <vector>

class Expression
{
public:

	Operator op;
	std::vector<IOperand const&> operands;
};
