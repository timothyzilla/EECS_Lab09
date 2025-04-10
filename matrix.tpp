#ifndef MATRIX_TPP
#define MATRIX_TPP

#include "matrix.h"

template <typename T>
Matrix<T>::Matrix(int size) : data(size, std::vector<T>(size)),size(size) {}

template <typename T>
void Matrix<T>::read(std::istream& in) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            in >> data[i][j];
}

template <typename T>
void Matrix<T>::print() const {
    for (const auto& row : data) {
        for (const auto& val : row)
            std::cout << std::setw(6) << val << " ";
        std::cout << "\n";
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    Matrix<T> result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    Matrix<T> result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            for (int k = 0; k < size; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

template <typename T>
T Matrix<T>::sumDiagonals() const {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i][i]; // Main diagonal
        if (i != size - 1 - i)
            sum += data[i][size - 1 - i]; // Secondary diagonal
    }
    return sum;
}

template <typename T>
void Matrix<T>::swapRows(int r1, int r2) {
    if (r1 >= 0 && r2 >= 0 && r1 < size && r2 < size)
        std::swap(data[r1], data[r2]);
}

template <typename T>
void Matrix<T>::swapCols(int c1, int c2) {
    if (c1 >= 0 && c2 >= 0 && c1 < size && c2 < size)
        for (int i = 0; i < size; ++i)
            std::swap(data[i][c1], data[i][c2]);
}

template <typename T>
void Matrix<T>::updateElement(int row, int col, T newValue) {
    if (row >= 0 && row < size && col >= 0 && col < size)
        data[row][col] = newValue;
}

#endif
