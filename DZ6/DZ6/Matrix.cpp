#include "Matrix.h"

Matrix::Matrix(std::vector<int>& values, unsigned row, unsigned column)
	:matrix(values),
	_row(row),
	_column(column)
{
	int different = row * column - matrix.size();
	matrix.resize(matrix.size() + different);
}

Matrix::Matrix(const Matrix& mat)
{
	Copy(mat);
}

Matrix& Matrix::operator=(const Matrix& mat)
{
	Copy(mat);
	return *this;
}

Matrix& Matrix::operator+(const Matrix& mat)
{
	return *this += mat;
}

Matrix& Matrix::operator-(const Matrix& mat)
{
	return *this -= mat;
}

Matrix& Matrix::operator*(const Matrix& mat)
{
	return *this *= mat;
}

Matrix& Matrix::operator+=(const Matrix& mat)
{
	if (!CompareSize(mat))
		return *this;
	for (size_t i = 0; i < matrix.size(); i++) {
		matrix[i] += mat.matrix[i];
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& mat)
{
	if (!CompareSize(mat))
		return *this;
	for (size_t i = 0; i < matrix.size(); i++) {
		matrix[i] -= mat.matrix[i];
	}
	return *this;
}


Matrix& Matrix::operator*=(const Matrix& mat)
{
	if (_column != mat._row)
		return *this;

	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < mat._column; j++)
		{
			for (int k = 0; k < _column; k++)
			{
				matrix[i + _row * j] += mat.matrix[k * j + _column] * matrix[k * _row + i];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator--()
{
	for (auto& value : matrix)
		--value;
	return *this;
}
Matrix& Matrix::operator--(int)
{
	for (auto& value : matrix)
		--value;
	return  *this;
}

std::istream& operator>>(std::istream& input, Matrix& mat)
{
	mat.matrix.clear();
	input >> mat._row >> mat._column;
	int value = 0;
	while (input >> value && (mat.matrix.size() < (mat._row * mat._column) - 1))
	{
		mat.matrix.push_back(value);
	}
	mat.matrix.push_back(value);
	return input;
}

std::ostream& operator<<(std::ostream& output, const Matrix& mat)
{

	for (size_t i = 0; i < mat.matrix.size(); ++i)
	{
		if (i % mat._row == 0)
			output << "\n";
		output << mat.matrix[i] << ", ";
	}
	return output;
}

Matrix& Matrix::operator++(int)
{
	for (auto& value : matrix)
		value--;
	return  *this;
}
Matrix& Matrix::operator++()
{
	for (auto& value : matrix)
		value++;
	return  *this;
}


bool Matrix::operator==(const Matrix& mat)
{
	return Equals(mat);
}

bool Matrix::operator!=(const Matrix& mat)
{
	return !Equals(mat);
}

const int& Matrix::operator()(unsigned column, unsigned row)
{

	int selectColumn = column * _row;
	size_t index = selectColumn + row;

	if (index > matrix.size() || index == matrix.size())
		return -1;
	return matrix[index];
}

bool Matrix::Equals(const Matrix& mat)
{
	if (!CompareSize(mat))
		return false;

	for (size_t i = 0; i < mat.matrix.size(); ++i)
		if (matrix[i] != mat.matrix[i])
			return false;
	return true;
}

bool Matrix::CompareSize(const Matrix& mat)
{
	return  _row == mat._row && _column == mat._column;
}

void Matrix::Copy(const Matrix& mat)
{
	matrix = mat.matrix;
	_row = mat._row;
	_column = mat._column;

}

