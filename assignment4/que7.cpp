#include <iostream>
#include <cmath> // For std::abs
#include <type_traits> // For std::is_arithmetic

using namespace std;

// Template function to calculate absolute value
template <typename T>
T absValue(T value) {
    // Ensure the type is arithmetic (int, float, double, etc.)
    static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");
    return std::abs(value);
}

int main() {
    int intVal = -5;
    double doubleVal = -3.14;
    float floatVal = -2.71f;

    cout << "Absolute value of " << intVal << " is " << absValue(intVal) << endl;
    cout << "Absolute value of " << doubleVal << " is " << absValue(doubleVal) << endl;
    cout << "Absolute value of " << floatVal << " is " << absValue(floatVal) << endl;

    return 0;
}
