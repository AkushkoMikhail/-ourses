#pragma once
#include <istream>


class Matrix3x3
{

public:
	Matrix3x3() = default;
	Matrix3x3(int v11, int v12, int v13,
		int v21, int v22, int v23,
		int v31, int v32, int v33);


	Matrix3x3(const Matrix3x3&);
	Matrix3x3& operator=(const Matrix3x3& mat);

	Matrix3x3& operator+(const Matrix3x3& mat);
	Matrix3x3& operator-(const Matrix3x3& mat);

	Matrix3x3& operator*(const Matrix3x3& mat);
	Matrix3x3& operator*=(const Matrix3x3& mat);

	Matrix3x3& operator+=(const Matrix3x3& mat);
	Matrix3x3& operator-=(const Matrix3x3& mat);

	Matrix3x3& operator++();
	Matrix3x3& operator--();

	Matrix3x3& operator++(int);
	Matrix3x3& operator--(int);

;
	bool operator==(const Matrix3x3& second);
	bool operator!=(const Matrix3x3& second);




	friend  std::istream& operator>> (std::istream& input, Matrix3x3& dt);
	friend 	std::ostream& operator<<(std::ostream& output, const Matrix3x3& D);

	const int& operator()(int row,int column)
	{
		return matrix[row][column];
	}

private:
	bool Equals(const  Matrix3x3& mat);
	void Copy(const Matrix3x3& mat);
	int matrix[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };

};
