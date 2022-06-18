#include "Matrix3x3.h"
#include <ostream>

Matrix3x3::Matrix3x3(
	int v11, int v12, int v13,
	int v21, int v22, int v23,
	int v31, int v32, int v33) :
	matrix{ {v31,v32,v33 },
	{ v21,v22,v23 },
	{ v11,v12,v13 } }

{
}

Matrix3x3::Matrix3x3(const Matrix3x3& mat)
{
	Copy(mat);
}

Matrix3x3& Matrix3x3::operator=(const Matrix3x3& mat)
{
	Copy(mat);
	return *this;
}

Matrix3x3& Matrix3x3::operator+(const Matrix3x3& mat)
{
	return *this += mat;
}

Matrix3x3& Matrix3x3::operator-(const Matrix3x3& mat)
{
	return *this -= mat;
}

Matrix3x3& Matrix3x3::operator*(const Matrix3x3& mat)
{
	return *this *= mat;
}

Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& mat)
{
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			matrix[j][i] += mat.matrix[j][i];
		}
	}
	return *this;
}

Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& mat)
{
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			matrix[j][i] -= mat.matrix[j][i];
		}
	}
	return *this;
}


Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& mat)
{
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			matrix[j][i] = matrix[0][i] * mat.matrix[j][0] + matrix[1][i] * mat.matrix[j][1] + matrix[2][i] * mat.matrix[j][2];
		}
	}
	return *this;
}

Matrix3x3& Matrix3x3::operator--()
{
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			matrix[j][i]--;
		}
	}
	return *this;
}
Matrix3x3& Matrix3x3::operator--(int)
{

	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			--matrix[j][i];
		}
	}
	return  *this;
}

std::istream& operator>>(std::istream& input, Matrix3x3& mat)
{
	input >> mat.matrix[2][0] >> mat.matrix[2][1] >> mat.matrix[2][2]
		>> mat.matrix[1][0] >> mat.matrix[1][1] >> mat.matrix[1][2]
		>> mat.matrix[0][0] >> mat.matrix[0][1] >> mat.matrix[0][2];
	return input;
}

std::ostream& operator<<(std::ostream& output, const Matrix3x3& D)
{
	output << "|" << D.matrix[2][0] << "," << D.matrix[2][1] << "," << D.matrix[2][2] << "|\n";
	output << "|" << D.matrix[1][0] << "," << D.matrix[1][1] << "," << D.matrix[1][2] << "|\n";
	output << "|" << D.matrix[0][0] << "," << D.matrix[0][1] << "," << D.matrix[0][2] << "|\n";

	return output;
}

Matrix3x3& Matrix3x3::operator++(int)
{
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			++matrix[j][i];
		}
	}
	return  *this;
}
Matrix3x3& Matrix3x3::operator++()
{
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			matrix[j][i]++;
		}
	}
	return  *this;
}


bool Matrix3x3::operator==(const Matrix3x3& mat)
{
	return Equals(mat);
}

bool Matrix3x3::operator!=(const Matrix3x3& mat)
{
	return !Equals(mat);
}

bool Matrix3x3::Equals(const Matrix3x3& mat)
{

	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			if (matrix[j][i] != mat.matrix[j][i])
				return false;
		}
	}
	return true;
}

void Matrix3x3::Copy(const Matrix3x3& mat)
{
	matrix[2][0] = mat.matrix[2][0];
	matrix[2][1] = mat.matrix[2][1];
	matrix[2][2] = mat.matrix[2][2];

	matrix[1][0] = mat.matrix[1][0];
	matrix[1][1] = mat.matrix[1][1];
	matrix[1][2] = mat.matrix[1][2];

	matrix[0][0] = mat.matrix[0][0];
	matrix[0][1] = mat.matrix[0][1];
	matrix[0][2] = mat.matrix[0][2];

}

