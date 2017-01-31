#include "OperandFactory.hpp"
#include "Expression.hpp"
#include "Operator.hpp"
#include "Lexer.hpp"
#include "Push.hpp"
#include <iostream>

int main(int argc, char **argv)
{(void)argc;(void)argv;
	Lexer lexer;

	auto const e = lexer.lex(argv[1]);
	std::cout << e->op.name << std::endl;
	std::cout << (e->operands)->at(0)->getType() << std::endl;
	std::cout << (e->operands)->at(0)->toString() << std::endl;
	return 0;
}
