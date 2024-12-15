#include <iostream>
#include <cmath>
using namespace std;

#ifndef M_PI
#define M_PI 3.14
#endif

// Base class
class Shape {
public:
    // Virtual function for calculating area
    virtual double area() const = 0; // Pure virtual function

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override the area function
    double area() const override {
        return M_PI * radius * radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override the area function
    double area() const override {
        return width * height;
    }
};

int main() {
    // Create objects of Circle and Rectangle
    Shape* shape1 = new Circle(5.0);
    Shape* shape2 = new Rectangle(4.0, 6.0);

    // Call the area function using base class pointers
    cout << "Area of Circle: " << shape1->area() << endl;
    cout << "Area of Rectangle: " << shape2->area() << endl;

    // Clean up
    delete shape1;
    delete shape2;

    return 0;
}
