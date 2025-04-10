#include <iostream>
#include <fstream>
#include "matrix.h"

int main() {
    std::string filename;
    std::cout << "Enter the matrix file name: ";
    std::cin >> filename;

    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: Could not open file.\n";
        return 1;
    }

    int n, typeFlag;
    inFile >> n >> typeFlag;

    if (typeFlag == 0) {
        Matrix<int> m1(n), m2(n);
        inFile >> m1 >> m2;

        std::cout << "Matrix 1:\n" << m1;
        std::cout << "Matrix 2:\n" << m2;

        std::cout << "\nAdding Matrices...\n" << (m1 + m2);
        std::cout << "\nMultiplying Matrices...\n" << (m1 * m2);
        std::cout << "\nSum of Diagonals: " << m1.sumDiagonals() << "\n";

        m1.swapRows(0, 1);
        std::cout << "\nAfter Swapping Rows 0 and 1:\n" << m1;

        m1.swapCols(0, 1);
        std::cout << "\nAfter Swapping Columns 0 and 1:\n" << m1;

        m1.updateElement(2, 2, 999);
        std::cout << "\nAfter Updating (2,2) to 999:\n" << m1;

    } else {
        Matrix<double> m1(n), m2(n);
        inFile >> m1 >> m2;

        std::cout << "Matrix 1:\n" << m1;
        std::cout << "Matrix 2:\n" << m2;

        std::cout << "\nAdding Matrices...\n" << (m1 + m2);
        std::cout << "\nMultiplying Matrices...\n" << (m1 * m2);
        std::cout << "\nSum of Diagonals: " << m1.sumDiagonals() << "\n";

        m1.swapRows(0, 1);
        std::cout << "\nAfter Swapping Rows 0 and 1:\n" << m1;

        m1.swapCols(0, 1);
        std::cout << "\nAfter Swapping Columns 0 and 1:\n" << m1;

        m1.updateElement(2, 2, 3.1415);
        std::cout << "\nAfter Updating (2,2) to 3.1415:\n" << m1;
    }

    return 0;
}
