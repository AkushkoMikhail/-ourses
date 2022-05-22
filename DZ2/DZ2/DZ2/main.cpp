#include <iostream>
#include <Utils/Equation.h>

int main()
{
	double a, b;
	std::cout << "solve the equation ax+b = 0 \n";
	std::cout << "Enter  a,b \n";
	std::cin >> a >> b;
	std::cout << "x is equal to: " << GetEquationResult(a, b);
	return 0;
}
