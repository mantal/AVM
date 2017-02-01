#include "VM.hpp"
#include "Expression.hpp"
#include <iostream>

VM::VM(std::vector<Expression const*> const& expressions_) : expressions(expressions_) { }
VM::VM(void) {}

void VM::run(void)
{
	try
	{
		for (auto it: expressions)
		{
			it->execute(*this);
		}
	}
	catch (std::exception const& e)
	{
		std::cerr << "Fatal error: " << e.what() << std::endl;
	}	
}

VM::~VM(void) { }
