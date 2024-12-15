#include <iostream>
#include <iomanip>
#include <string>

// Define a manipulator function
std::ostream& customFormat(std::ostream& out) {
    out << "[Prefix] ";
    return out;
}

// Define another manipulator function for suffix
std::ostream& customSuffix(std::ostream& out) {
    out << " [Suffix]";
    return out;
}

int main() {
    std::string message = "Hello, World!";

    // Use the custom manipulators
    std::cout << customFormat << message << customSuffix << std::endl;

    return 0;
}
