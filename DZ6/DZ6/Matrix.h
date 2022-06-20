#pragma once
#include <istream>
#include <vector>


class Matrix
{

public:
	Matrix() = default;
	Matrix(std::vector<int>& values, unsigned row, unsigned column);
	Matrix(const Matrix&);
	Matrix& operator=(const Matrix& mat);

	Matrix& operator+(const Matrix& mat);
	Matrix& operator-(const Matrix& mat);

	Matrix& operator*(const Matrix& mat);
	Matrix& operator*=(const Matrix& mat);

	Matrix& operator+=(const Matrix& mat);
	Matrix& operator-=(const Matrix& mat);

	Matrix& operator++();
	Matrix& operator--();

	Matrix& operator++(int);
	Matrix& operator--(int);

	;
	bool operator==(const Matrix& second);
	bool operator!=(const Matrix& second);




	friend  std::istream& operator>> (std::istream& input, Matrix& dt);
	friend 	std::ostream& operator<<(std::ostream& output, const Matrix& D);
	const unsigned& GetRow()const
	{
		return _row;
	}

	const unsigned& GetColumn()const
	{
		return _column;
	}
	const int& operator()(unsigned row, unsigned column);


private:
	bool Equals(const  Matrix& mat);

	bool CompareSize(const Matrix& mat);
	void Copy(const Matrix& mat);
	unsigned _row = 1;
	unsigned _column = 1;
	std::vector<int> matrix;
};
