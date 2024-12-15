#include <iostream>
using namespace std;

int main() {
    int var = 42;  // Declare an integer variable and initialize it
    int *ptr;      // Declare a pointer to an integer

    ptr = &var;    // Assign the address of var to the pointer

    // Output the value of var using the pointer
    cout << "Value of var: " << var << endl;
    cout << "Value of var using pointer: " << *ptr << endl;

    // Output the address of var
    cout << "Address of var: " << &var << endl;
    cout << "Address stored in pointer: " << ptr << endl;

    // Modify the value of var using the pointer
    *ptr = 100;
    cout << "New value of var after modification through pointer: " << var << endl;

    return 0;
}

/*
Certainly! Let's go through the `que3.cpp` program step by step to understand how it works.

### Overview

The program demonstrates the use of pointers in C++. It shows how to declare a pointer, assign it the address of a variable, and use the pointer to access and modify the value of the variable.

### Code Breakdown

```cpp
#include <iostream>
using namespace std;
```
- These lines include the iostream library, which is necessary for input and output operations, and use the standard namespace.

```cpp
int main() {
    int var = 42;  // Declare an integer variable and initialize it
    int *ptr;      // Declare a pointer to an integer
```
- An integer variable `var` is declared and initialized with the value `42`.
- A pointer `ptr` is declared to hold the address of an integer.

```cpp
    ptr = &var;    // Assign the address of var to the pointer
```
- The address of `var` is assigned to `ptr` using the address-of operator `&`.

```cpp
    // Output the value of var using the pointer
    cout << "Value of var: " << var << endl;
    cout << "Value of var using pointer: " << *ptr << endl;
```
- The program outputs the value of `var` directly and also by dereferencing the pointer `ptr` using the `*` operator, which accesses the value stored at the address `ptr` points to.

```cpp
    // Output the address of var
    cout << "Address of var: " << &var << endl;
    cout << "Address stored in pointer: " << ptr << endl;
```
- The program outputs the address of `var` using the address-of operator `&`.
- It also outputs the address stored in `ptr`, which should be the same as the address of `var`.

```cpp
    // Modify the value of var using the pointer
    *ptr = 100;
    cout << "New value of var after modification through pointer: " << var << endl;
```
- The value of `var` is modified through the pointer by assigning `100` to `*ptr`.
- The program then outputs the new value of `var`, demonstrating that the change was successfully made through the pointer.

```cpp
    return 0;
}
```
- The program returns `0`, indicating successful execution.

### Summary

This program provides a basic understanding of how pointers work in C++. It shows how to use pointers to access and modify the value of a variable indirectly. By using pointers, you can manipulate data stored in memory locations directly, which is a powerful feature in C++ programming.
*/