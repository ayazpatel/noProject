#include <iostream>
#include <iomanip> // For std::setprecision

int main() {
    double number = 1234.56789;

    // Default output
    std::cout << "Default output: " << number << std::endl;

    // Set fixed-point notation and precision
    std::cout.setf(std::ios::fixed);
    std::cout << "Fixed-point notation: " << number << std::endl;

    // Set precision to 2 decimal places
    std::cout.precision(2);
    std::cout << "Fixed-point with precision 2: " << number << std::endl;

    // Set scientific notation
    std::cout.setf(std::ios::scientific, std::ios::floatfield);
    std::cout << "Scientific notation: " << number << std::endl;

    // Unset fixed and scientific notation
    std::cout.unsetf(std::ios::floatfield);
    std::cout << "Default floatfield: " << number << std::endl;

    // Set precision to 4 decimal places
    std::cout << std::setprecision(4);
    std::cout << "Precision 4: " << number << std::endl;

    // Set showpoint to display trailing zeros
    std::cout.setf(std::ios::showpoint);
    std::cout << "Showpoint with precision 4: " << number << std::endl;

    // Unset showpoint
    std::cout.unsetf(std::ios::showpoint);
    std::cout << "Unset showpoint: " << number << std::endl;

    return 0;
}
