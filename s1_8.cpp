#include <iostream>

class Matrix {
  
public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        data = new int[rows * cols](); // Allocate memory for the matrix and initialize to 0
    }

    ~Matrix() {
        delete[] data; // Free the allocated memory
    }

    void setValue(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row * cols + col] = value;
        }
    }

    // Member function to print the matrix
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i * cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int rows, cols; // Declare rows and cols as private member variables
    int* data; // Pointer to the matrix data
};

int main() {
    Matrix m1(2, 3);
    m1.setValue(0, 0, 1);
    m1.setValue(0, 1, 2);
    m1.setValue(0, 2, 3);
    m1.setValue(1, 0, 4);
    m1.setValue(1, 1, 5);
    m1.setValue(1, 2, 6);

    m1.print(); // Use the print function to display the matrix

    return 0;
}
