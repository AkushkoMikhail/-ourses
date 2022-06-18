
#include <iostream>

#include "Matrix3x3.h"

int main() {

	Matrix3x3 m = Matrix3x3(1,1,1,2,2,2,3,3,3);

	Matrix3x3 first = Matrix3x3(1,1,1,1,1,1,1,1,1);
	Matrix3x3 second = Matrix3x3(3, 3, 3, 3, 3, 3, 3, 3, 3);


	Matrix3x3 third = second;

	bool isTrue = third == second;
	bool isFalse = third == first;


	third +=first;
	third -= first;

	third = third + first;
	third = third - first;

	third = third * m;
	third *= m;

	third++;
	third--;

	--third;
	++third;

	int i = third(1, 1);

	std::cout << third;
	std::cin >> m;
	std::cout << m;
	return 0;
};