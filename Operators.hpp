#pragma once

#include "Operator.hpp"

class Push : public Operator
{
public:
	Push(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const &operands) const;
};

class Pop : public Operator
{
public:
	Pop(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const& operands) const;
};

class Dump : public Operator
{
public:
	Dump(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const& operands) const;
};

class Assert : public Operator
{
public:
	Assert(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const& operands) const;
};


class Add : public Operator
{
public:
	Add(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const& operands) const;
};

class Sub : public Operator
{
public:
	Sub(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const& operands) const;
};

class Mul : public Operator
{
public:
	Mul(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const& operands) const;
};

class Div : public Operator
{
public:
	Div(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const& operands) const;
};

class Mod : public Operator
{
public:
	Mod(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const& operands) const;
};

class Print : public Operator
{
public:
	Print(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const &operands) const;
};

class Exit : public Operator
{
public:
	Exit(void);
	virtual void execute(VM &vm, std::vector<IOperand const*> const &operands) const;
};

class NoOp : public Operator
{
public:
	NoOp(void);
};
