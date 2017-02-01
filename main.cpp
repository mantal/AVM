#include "OperandFactory.hpp"
#include "Expression.hpp"
#include "Operator.hpp"
#include "Lexer.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <fstream>
#include <memory>

static std::vector<Expression const*> *fromStdin(void)
{
	auto expressions = new std::vector<Expression const*>;
	Lexer lexer;

	for(std::string line; getline(std::cin, line);)
	{
		if (line == ";;")//TODO better?
			break ;

		try
		{
			expressions->push_back(lexer.lex(line));
		}
		catch (std::exception const& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return expressions;
}

static std::vector<Expression const*> *fromFile(std::string const& fileName)
{
	auto expressions = new std::vector<Expression const*>;
	Lexer lexer;
	int i = 1;
	bool error = false;
	std::fstream stream(fileName);

	for(std::string line; getline(stream, line); i++)
	{
		try
		{
			expressions->push_back(lexer.lex(line));
		}
		catch (std::exception const& e)
		{
			std::cerr << fileName << ": line " << i << ": " << e.what() << std::endl;
			error = true;
		}
	}
	if (error)
		return nullptr;
	return expressions;
}

int main(int argc, char **argv)
{
	VM vm;

	if (argc == 1)
	{
		vm.expressions = *fromStdin();
		vm.run();
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		auto const e = fromFile(argv[i]);
		if (e == nullptr)
			continue ;
		vm.expressions = *e;
		vm.run();
	}
	return 0;
}
