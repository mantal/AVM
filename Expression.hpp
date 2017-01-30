#pragma once

#include "IOperand.hpp"
#include "Operator.hpp"
#include "VM.hpp"
#include <vector>

class Expression//TODO sotcker ligne + char pour les msg d'erreur
{
public:

	Expression(Operator const& op, std::vector<IOperand const*> operands);

	void execute(VM &vm) const;

	Operator const& op;
	std::vector<IOperand const*> const operands;

private:

	Expression& operator=(Operator const&);
	Expression(void);
	Expression(Expression const&);
};
