#pragma once

#include "IOperand.hpp"
#include <deque>
#include <vector>

class Expression;

class VM
{
public:

	VM(std::vector<Expression const*> const& expressions);

	void run(void);

	~VM(void);

	std::deque<IOperand const*> stack;

private:
		
	std::vector<Expression const*> _expressions;

	VM(VM const&);
	VM& operator=(VM const&);
};
