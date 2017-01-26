#include "Operand.tpp"

int main()
{
	Operand<int> a(1, eOperandType::Int8);
	Operand<int> b(2, eOperandType::Int8);
	std::cout << (a + b)->toString();
	return 0;
}
