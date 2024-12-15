#include <iostream>

class Matrix {
public:
    int rows, cols;
    int data[2][2];

    Matrix(int r, int c) : rows(r), cols(c) {}

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);

    mat1.data[0][0] = 1; mat1.data[0][1] = 2;
    mat1.data[1][0] = 3; mat1.data[1][1] = 4;

    mat2.data[0][0] = 5; mat2.data[0][1] = 6;
    mat2.data[1][0] = 7; mat2.data[1][1] = 8;

    Matrix resultAdd = mat1 + mat2;
    Matrix resultSub = mat1 - mat2;

    std::cout << "Matrix 1:" << std::endl;
    mat1.display();

    std::cout << "Matrix 2:" << std::endl;
    mat2.display();

    std::cout << "Addition Result:" << std::endl;
    resultAdd.display();

    std::cout << "Subtraction Result:" << std::endl;
    resultSub.display();

    return 0;
}

/*
Certainly! Let's go through the `que1.cpp` program step by step to understand how it works.

### Overview

The program defines a `Matrix` class that supports basic matrix operations such as addition and subtraction. It demonstrates the use of operator overloading to perform these operations on matrices.

### Code Breakdown

```cpp
#include <iostream>
```
- This line includes the iostream library, which is necessary for input and output operations.

```cpp
class Matrix {
public:
    int rows, cols;
    int data[2][2];
```
- The `Matrix` class is defined with public access. It contains three members:
  - `rows` and `cols` to store the dimensions of the matrix.
  - `data` is a 2x2 array to store the matrix elements.

```cpp
    Matrix(int r, int c) : rows(r), cols(c) {}
```
- This is a constructor for the `Matrix` class. It initializes the `rows` and `cols` with the provided values `r` and `c`.

```cpp
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
```
- This function overloads the `+` operator to add two matrices.
- It creates a new `Matrix` object `result` with the same dimensions.
- It iterates over each element of the matrices, adds corresponding elements, and stores the result in `result`.
- Finally, it returns the resulting matrix.

```cpp
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
```
- This function overloads the `-` operator to subtract one matrix from another.
- It follows a similar process as the `+` operator, but performs subtraction instead.

```cpp
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
```
- The `display` function prints the matrix to the console.
- It iterates over each element and prints it, formatting the output as a matrix.

```cpp
int main() {
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);

    mat1.data[0][0] = 1; mat1.data[0][1] = 2;
    mat1.data[1][0] = 3; mat1.data[1][1] = 4;

    mat2.data[0][0] = 5; mat2.data[0][1] = 6;
    mat2.data[1][0] = 7; mat2.data[1][1] = 8;
```
- The `main` function begins by creating two `Matrix` objects, `mat1` and `mat2`, each with dimensions 2x2.
- It initializes the `data` arrays of `mat1` and `mat2` with specific values.

```cpp
    Matrix resultAdd = mat1 + mat2;
    Matrix resultSub = mat1 - mat2;
```
- These lines demonstrate the use of overloaded operators. `mat1 + mat2` calls the overloaded `+` operator, and `mat1 - mat2` calls the overloaded `-` operator.
- The results are stored in `resultAdd` and `resultSub`.

```cpp
    std::cout << "Matrix 1:" << std::endl;
    mat1.display();

    std::cout << "Matrix 2:" << std::endl;
    mat2.display();

    std::cout << "Addition Result:" << std::endl;
    resultAdd.display();

    std::cout << "Subtraction Result:" << std::endl;
    resultSub.display();

    return 0;
}
```
- The program prints `mat1`, `mat2`, and the results of their addition and subtraction using the `display` function.
- Finally, the program returns 0, indicating successful execution.

### Summary

This program demonstrates basic matrix operations using operator overloading in C++. It allows you to add and subtract matrices and display the results, showcasing how operator overloading can simplify mathematical operations on custom data types.
*/