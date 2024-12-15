#include <iostream>

// Define the Complex class
class Complex {
private:
    double real;
    double imag;

public:
    // Constructor to initialize a Complex object
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload the + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Method to display the complex number
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    // Create two Complex objects
    Complex c1(3.0, 4.0);
    Complex c2(1.5, 2.5);

    // Use overloaded + operator
    Complex sum = c1 + c2;
    std::cout << "Sum: ";
    sum.display();

    // Use overloaded - operator
    Complex difference = c1 - c2;
    std::cout << "Difference: ";
    difference.display();

    return 0;
}
