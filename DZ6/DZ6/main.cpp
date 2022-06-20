#include <iostream>

#include "Matrix.h"

int main() {

	std::vector<int> testValue = { 4,2,9,0 };
	std::vector<int> firstValue = { 3,1,-3,4};
	std::vector<int> secondValue = { 3, 3, 3, 3, 3, 3, 3, 3, 3 };

	Matrix first = Matrix(firstValue,2,2);
	Matrix m = Matrix(testValue,2,2);
	Matrix second = Matrix(secondValue,3,3);
	std::cout << m;
	std::cout << first;


	m *= first;


	Matrix third = second;

	bool isTrue = third == second;
	bool isFalse = third == first;

	std::cout << "\n ------------ \n";
	std::cout << first(0, -1) << "\n";
	std::cout << first(0, 1) << "\n";
	std::cout << first(0, 2) << "\n";

	std::cout << first(3, 0) << "\n";
	std::cout << first(3, 1) << "\n";
	std::cout << first(3, 3) << "\n";

	third +=first;
	third -= first;

	third = third + first;
	third = third - first;


	third++;
	third--;

	--third;
	++third;

	third = third * m;
	third *= m;




	std::cin >> m;
	std::cout << m;
	return 0;
};