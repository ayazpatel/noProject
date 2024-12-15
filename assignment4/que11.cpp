#include <iostream>
#include <string>

// Define the Manager class
class Manager {
private:
    std::string name;
    int age;

public:
    // Constructor to initialize a Manager object
    Manager(const std::string& managerName, int managerAge) : name(managerName), age(managerAge) {}

    // Method to display manager details
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Create an array of Manager objects
    const int numManagers = 3;
    Manager managers[numManagers] = {
        Manager("Alice Johnson", 45),
        Manager("Bob Smith", 50),
        Manager("Charlie Brown", 38)
    };

    // Display information for each manager
    std::cout << "List of Managers:" << std::endl;
    for (int i = 0; i < numManagers; ++i) {
        managers[i].displayInfo();
    }

    return 0;
}
