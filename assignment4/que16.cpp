#include <iostream>

// Define the Matrix class
class Matrix {
private:
    int data[2][2];

public:
    // Constructor to initialize a Matrix object
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    // Overload the * operator for matrix multiplication
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        result.data[0][0] = data[0][0] * other.data[0][0] + data[0][1] * other.data[1][0];
        result.data[0][1] = data[0][0] * other.data[0][1] + data[0][1] * other.data[1][1];
        result.data[1][0] = data[1][0] * other.data[0][0] + data[1][1] * other.data[1][0];
        result.data[1][1] = data[1][0] * other.data[0][1] + data[1][1] * other.data[1][1];
        return result;
    }

    // Overload the == operator for matrix comparison
    bool operator==(const Matrix& other) const {
        return data[0][0] == other.data[0][0] && data[0][1] == other.data[0][1] &&
               data[1][0] == other.data[1][0] && data[1][1] == other.data[1][1];
    }

    // Overload the >> operator for input
    friend std::istream& operator>>(std::istream& in, Matrix& matrix) {
        std::cout << "Enter elements of the matrix (row-wise): ";
        in >> matrix.data[0][0] >> matrix.data[0][1] >> matrix.data[1][0] >> matrix.data[1][1];
        return in;
    }

    // Overload the << operator for output
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
        out << matrix.data[0][0] << " " << matrix.data[0][1] << "\n"
            << matrix.data[1][0] << " " << matrix.data[1][1] << "\n";
        return out;
    }
};

int main() {
    Matrix mat1, mat2;
    
    // Input matrices
    std::cout << "Matrix 1:\n";
    std::cin >> mat1;
    std::cout << "Matrix 2:\n";
    std::cin >> mat2;

    // Display matrices
    std::cout << "Matrix 1:\n" << mat1;
    std::cout << "Matrix 2:\n" << mat2;

    // Multiply matrices
    Matrix product = mat1 * mat2;
    std::cout << "Product of Matrix 1 and Matrix 2:\n" << product;

    // Compare matrices
    if (mat1 == mat2) {
        std::cout << "Matrix 1 is equal to Matrix 2.\n";
    } else {
        std::cout << "Matrix 1 is not equal to Matrix 2.\n";
    }

    return 0;
}
