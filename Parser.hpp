#pragma once

#include "Expression.hpp"
#include <vector>
#include <string>

class Parser
{
public:

	Expression *parse(Operator const *, std::vector<eOperandType> const&, std::vector<std::string const*> const&) const;
	
private:
	
};
