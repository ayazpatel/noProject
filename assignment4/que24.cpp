#include <iostream>

// Template function to find the maximum of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Using the template function with integers
    int int1 = 10, int2 = 20;
    std::cout << "Max of " << int1 << " and " << int2 << " is " << findMax(int1, int2) << std::endl;

    // Using the template function with doubles
    double double1 = 15.5, double2 = 10.3;
    std::cout << "Max of " << double1 << " and " << double2 << " is " << findMax(double1, double2) << std::endl;

    // Using the template function with characters
    char char1 = 'a', char2 = 'z';
    std::cout << "Max of '" << char1 << "' and '" << char2 << "' is '" << findMax(char1, char2) << "'" << std::endl;

    return 0;
}
