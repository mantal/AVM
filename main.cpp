#include "Operand.tpp"

int main()
{
	Operand<int> a(1);
	Operand<int> b(2);
	std::cout << (a + b)->toString();
	return 0;
}
