#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    // Add some elements to the vector
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);

    // Display the elements of the vector
    std::cout << "Numbers in the vector: ";
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Remove the last element
    numbers.pop_back();

    // Display the elements again
    std::cout << "After popping the last element: ";
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
