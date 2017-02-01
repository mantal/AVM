#include "VM.hpp"
#include "Expression.hpp"
#include <iostream>

VM::VM(std::vector<Expression const*> const& expressions_) : expressions(expressions_) { }
VM::VM(void) { }

void VM::run(void)
{
	try
	{
		for (auto it: expressions)
		{
			it->execute(*this);
			if (exit)
				break ;
		}
		if (exit == false)
			throw std::runtime_error("The program ended but exit was not called");
	}
	catch (std::exception const& e)
	{
		std::cerr << "Fatal error: " << e.what() << std::endl;
	}
}

VM::~VM(void) { }
