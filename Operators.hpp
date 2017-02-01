#pragma once

#include "Operator.hpp"

class Add : public Operator
{
public:
	Add(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const& operands) const;
};

class Push : public Operator
{
public:
	Push(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const &operands) const;
};

class NoOp : public Operator
{
public:
	NoOp(void);
};
