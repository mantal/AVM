#include "OperandFactory.hpp"
#include "Expression.hpp"
#include "Operator.hpp"
#include "Lexer.hpp"
#include "Push.hpp"
#include <iostream>
#include <fstream>
#include <memory>

std::vector<Expression const*> *fromStdin(void)
{
	auto expressions = new std::vector<Expression const*>;
	Lexer lexer;

	for(std::string line; getline(std::cin, line);)
	{
		if (line == ";;")//TODO better?
			break ;
		expressions->push_back(lexer.lex(line));
	}
	return expressions;
}

int main(int argc, char **argv)
{
	VM vm;

	if (argc == 1)
	{
		vm.expressions = *fromStdin();
		vm.run();
	}
	return 0;
}
