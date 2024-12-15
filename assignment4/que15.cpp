#include <iostream>
#include <string>

// Define the Person class
class Person {
private:
    std::string name;
    int age;

public:
    // Constructor to initialize a Person object
    Person(const std::string& personName, int personAge) : name(personName), age(personAge) {
        std::cout << "Person object created!" << std::endl;
    }

    // Method to display person details
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    // Destructor to clean up when the object is deleted
    ~Person() {
        std::cout << "Person object destroyed!" << std::endl;
    }
};

int main() {
    // Dynamically allocate memory for a Person object
    Person* personPtr = new Person("Alice Smith", 28);

    // Use the object
    personPtr->displayInfo();

    // Deallocate memory
    delete personPtr;

    return 0;
}
