#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <iomanip>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    int size;

public:
    Matrix(int size = 0);
    void read(std::istream& in);
    void print() const;
    T sumDiagonals() const;
    void swapRows(int r1, int r2);
    void swapCols(int c1, int c2);
    void updateElement(int row, int col, T newValue);

    // Operator overloads
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;

    friend std::istream& operator>>(std::istream& in, Matrix<T>& matrix) {
        matrix.read(in);
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
        matrix.print();
        return out;
    }
};

#include "matrix.tpp" // Include template implementation

#endif
