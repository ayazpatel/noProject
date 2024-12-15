#include <iostream>

// Forward declaration of the Box class
class Box;

// Friend function declaration
void showVolume(const Box&);

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor to initialize a Box object
    Box(double l, double w, double h) : length(l), width(w), height(h) {}

    // Declare showVolume as a friend function
    friend void showVolume(const Box&);
};

// Friend function definition
void showVolume(const Box& b) {
    double volume = b.length * b.width * b.height;
    std::cout << "Volume of the box: " << volume << std::endl;
}

int main() {
    // Create a Box object
    Box myBox(3.0, 4.0, 5.0);

    // Use the friend function to display the volume of the box
    showVolume(myBox);

    return 0;
}
