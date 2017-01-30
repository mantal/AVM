#include "OperandFactory.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	auto factory = new OperandFactory();
	const IOperand& a = *factory->createOperand(eOperandType::Int16, argv[1]);
	const IOperand& b = *factory->createOperand(eOperandType::Int16, argv[2]);

	std::cout << (a + b)->toString() << std::endl;

	return 0;
}
