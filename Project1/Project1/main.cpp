#include <iostream>
int main()
{
	float a, b, c;
	std::cin >> a >> b >> c;
	float result = pow((a * b * c), 1.0f / 3.0f);
	std::cout << result;

	return 0;
}
