#include <iostream>
#include <string>
using namespace std;

// Base class: Vehicle
class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string b, int y) : brand(b), year(y) {}

    void displayInfo() const {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

// Derived class: Car (inherits from Vehicle)
class Car : public Vehicle {
private:
    string model;

public:
    Car(string b, int y, string m) : Vehicle(b, y), model(m) {}

    void displayCarInfo() const {
        displayInfo();
        cout << "Model: " << model << endl;
    }
};

// Class demonstrating containership: Garage
class Garage {
private:
    Car car;

public:
    Garage(Car c) : car(c) {}

    void showCarInGarage() const {
        cout << "Car in the garage:" << endl;
        car.displayCarInfo();
    }
};

int main() {
    // Create a Car object
    Car myCar("Toyota", 2020, "Corolla");

    // Create a Garage object containing the Car
    Garage myGarage(myCar);

    // Display information about the car in the garage
    myGarage.showCarInGarage();

    return 0;
}

/*
Certainly! Let's go through the `que5.cpp` program step by step to understand how it works.

### Overview

The program demonstrates basic concepts of object-oriented programming in C++, including inheritance and containership. It defines a `Vehicle` class as a base class, a `Car` class that inherits from `Vehicle`, and a `Garage` class that contains a `Car` object.

### Code Breakdown

```cpp
#include <iostream>
#include <string>
using namespace std;
```
- These lines include the iostream and string libraries, which are necessary for input/output operations and string handling, respectively.

```cpp
// Base class: Vehicle
class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string b, int y) : brand(b), year(y) {}

    void displayInfo() const {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};
```
- The `Vehicle` class is defined as a base class with two protected members: `brand` and `year`.
- It has a constructor that initializes these members and a member function `displayInfo` to print the vehicle's brand and year.

```cpp
// Derived class: Car (inherits from Vehicle)
class Car : public Vehicle {
private:
    string model;

public:
    Car(string b, int y, string m) : Vehicle(b, y), model(m) {}

    void displayCarInfo() const {
        displayInfo();
        cout << "Model: " << model << endl;
    }
};
```
- The `Car` class inherits from `Vehicle` and adds a private member `model`.
- It has a constructor that initializes the base class members using an initializer list and also initializes `model`.
- The `displayCarInfo` function calls `displayInfo` from the base class and then prints the car's model.

```cpp
// Class demonstrating containership: Garage
class Garage {
private:
    Car car;

public:
    Garage(Car c) : car(c) {}

    void showCarInGarage() const {
        cout << "Car in the garage:" << endl;
        car.displayCarInfo();
    }
};
```
- The `Garage` class demonstrates containership by having a `Car` object as a private member.
- It has a constructor that initializes the `car` member.
- The `showCarInGarage` function prints a message and calls `displayCarInfo` on the `car` object to show its details.

```cpp
int main() {
    // Create a Car object
    Car myCar("Toyota", 2020, "Corolla");

    // Create a Garage object containing the Car
    Garage myGarage(myCar);

    // Display information about the car in the garage
    myGarage.showCarInGarage();

    return 0;
}
```
- The `main` function creates a `Car` object `myCar` with brand "Toyota", year 2020, and model "Corolla".
- It then creates a `Garage` object `myGarage` that contains `myCar`.
- Finally, it calls `showCarInGarage` to display the car's information.

### Summary

This program illustrates the use of inheritance and containership in C++. The `Car` class inherits from `Vehicle`, allowing it to use and extend the functionality of the base class. The `Garage` class contains a `Car` object, demonstrating how objects can be composed to build more complex structures. The program outputs the details of a car stored in a garage, showcasing these object-oriented principles.
*/