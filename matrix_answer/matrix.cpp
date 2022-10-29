#include "matrix.h"

namespace mjuoop {
	Matrix::Matrix(const double* values) {
		for (int i = 0; i < NUM_ELEMENTS; ++i) {
			this->values[i] = values[i];
		}
	}

	Matrix Matrix::operator+(const Matrix& b) const {
		double newValues[NUM_ELEMENTS] = {};

		for (int i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
			newValues[i] = values[i] + b.values[i];
		}

		return Matrix(newValues);
	}

	Matrix Matrix::operator-(const Matrix& b) const {
		double newValues[NUM_ELEMENTS] = {};

		for (int i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
			newValues[i] = values[i] - b.values[i];
		}

		return Matrix(newValues);
	}

	Matrix Matrix::operator*(const Matrix& b) const {
		double newValues[NUM_ELEMENTS] = {};
		for (int i = 0; i < NUM_ROWS; ++i) {
			for (int j = 0; j < NUM_COLS; ++j) {
				double sum = 0.0;
				for (int k = 0; k < NUM_COLS; ++k) {
					sum += values[xyToIndex(i, k)] * b.values[xyToIndex(k, j)];
				}
				newValues[xyToIndex(i, j)] = sum;
			}
		}

		return Matrix(newValues);
	}

	Matrix& Matrix::operator+=(const Matrix& b) {
		*this = this->operator+(b);
		return *this;
	}

	Matrix& Matrix::operator-=(const Matrix& b) {
		*this = this->operator-(b);
		return *this;
	}

	Matrix& Matrix::operator*=(const Matrix& b) {
		*this = this->operator*(b);
		return *this;
	}

	Matrix::operator bool() const {
		for (int i = 0; i < NUM_ELEMENTS; ++i) {
			if (values[i] != 0.0) {
				return true;
			}
		}
		return false;
	}
}