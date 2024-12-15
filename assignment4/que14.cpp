#include <iostream>
#include <string>

// Define the Person class
class Person {
private:
    std::string name;
    int age;

public:
    // Constructor to initialize a Person object
    Person(const std::string& personName, int personAge) : name(personName), age(personAge) {}

    // Copy constructor
    Person(const Person& other) : name(other.name), age(other.age) {
        std::cout << "Copy constructor called!" << std::endl;
    }

    // Method to display person details
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Create a Person object
    Person person1("John Doe", 30);
    std::cout << "Original person:" << std::endl;
    person1.displayInfo();

    // Use the copy constructor to create a new Person object as a copy of person1
    Person person2 = person1;
    std::cout << "Copied person:" << std::endl;
    person2.displayInfo();

    return 0;
}
