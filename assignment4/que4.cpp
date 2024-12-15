#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    // Constructor to initialize matrix with given dimensions
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0; // Initialize all elements to 0
            }
        }
    }

    // Destructor to free allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overload prefix ++ operator
    Matrix& operator++() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ++data[i][j];
            }
        }
        return *this;
    }

    // Overload postfix ++ operator
    Matrix operator++(int) {
        Matrix temp = *this; // Create a copy of the current state
        ++(*this); // Use the prefix increment to increment the matrix
        return temp; // Return the copy
    }
};

int main() {
    Matrix mat(2, 2);

    cout << "Initial matrix:" << endl;
    mat.display();

    ++mat; // Prefix increment
    cout << "\nAfter prefix increment:" << endl;
    mat.display();

    mat++; // Postfix increment
    cout << "\nAfter postfix increment:" << endl;
    mat.display();

    return 0;
}

/*
Certainly! Let's go through the `que4.cpp` program step by step to understand how it works.

### Overview

The program defines a `Matrix` class that supports increment operations on its elements. It demonstrates the use of operator overloading to perform both prefix and postfix increment operations on a matrix.

### Code Breakdown

```cpp
#include <iostream>
using namespace std;
```
- These lines include the iostream library, which is necessary for input and output operations, and use the standard namespace.

```cpp
class Matrix {
private:
    int rows, cols;
    int** data;
```
- The `Matrix` class is defined with private members:
  - `rows` and `cols` to store the dimensions of the matrix.
  - `data` is a pointer to a pointer, used to dynamically allocate a 2D array for the matrix elements.

```cpp
public:
    // Constructor to initialize matrix with given dimensions
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0; // Initialize all elements to 0
            }
        }
    }
```
- The constructor initializes the matrix with the given dimensions `r` and `c`.
- It allocates memory for a 2D array and initializes all elements to 0.

```cpp
    // Destructor to free allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
```
- The destructor frees the dynamically allocated memory to prevent memory leaks.

```cpp
    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
```
- The `display` function prints the matrix to the console, iterating over each element.

```cpp
    // Overload prefix ++ operator
    Matrix& operator++() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ++data[i][j];
            }
        }
        return *this;
    }
```
- The prefix `++` operator is overloaded to increment each element of the matrix.
- It returns a reference to the modified matrix.

```cpp
    // Overload postfix ++ operator
    Matrix operator++(int) {
        Matrix temp = *this; // Create a copy of the current state
        ++(*this); // Use the prefix increment to increment the matrix
        return temp; // Return the copy
    }
```
- The postfix `++` operator is overloaded to increment each element of the matrix.
- It creates a copy of the matrix, increments the original matrix using the prefix `++`, and returns the copy.

```cpp
int main() {
    Matrix mat(2, 2);

    cout << "Initial matrix:" << endl;
    mat.display();

    ++mat; // Prefix increment
    cout << "\nAfter prefix increment:" << endl;
    mat.display();

    mat++; // Postfix increment
    cout << "\nAfter postfix increment:" << endl;
    mat.display();

    return 0;
}
```
- The `main` function creates a `Matrix` object `mat` with dimensions 2x2.
- It displays the initial matrix, performs a prefix increment, displays the matrix again, performs a postfix increment, and displays the matrix once more.

### Summary

This program demonstrates how to overload both the prefix and postfix `++` operators for a matrix class, allowing you to increment all elements of the matrix. It showcases dynamic memory management and operator overloading in C++.
*/