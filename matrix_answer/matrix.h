#pragma once

namespace mjuoop {
	class Matrix {
	public:
		static const int NUM_ROWS = 2;
		static const int NUM_COLS = 2;

	private:
		static const int NUM_ELEMENTS = NUM_ROWS * NUM_COLS;

		inline static int xyToIndex(const int x, const int y) {
			return x * NUM_COLS + y;
		}

		double values[NUM_ELEMENTS];

	public:
		Matrix(const double* values);

		Matrix operator+(const Matrix& b) const;
		Matrix operator-(const Matrix& b) const;
		Matrix operator*(const Matrix& b) const;

		Matrix& operator+=(const Matrix& b);
		Matrix& operator-=(const Matrix& b);
		Matrix& operator*=(const Matrix& b);

		operator bool() const;
	};
}