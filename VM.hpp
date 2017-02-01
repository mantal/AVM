#pragma once

#include "IOperand.hpp"
#include <deque>
#include <vector>

class Expression;

class VM
{
public:

	VM(void);
	VM(std::vector<Expression const*> const& expressions);

	void run(void);

	~VM(void);

	std::deque<IOperand const*> stack;
	std::vector<Expression const*> expressions;

private:

	VM(VM const&);
	VM& operator=(VM const&);
};
