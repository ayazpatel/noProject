#include <iostream>
#include <stdexcept>

// Define the template class Stack
template <typename T, size_t MaxSize>
class Stack {
private:
    T elements[MaxSize];  // Use a normal array to store stack elements
    int topIndex;         // Index of the top element

public:
    // Constructor to initialize the stack
    Stack() : topIndex(-1) {}

    // Push an element onto the stack
    void push(const T& element) {
        if (topIndex >= static_cast<int>(MaxSize) - 1) {
            throw std::out_of_range("Stack<>::push(): stack overflow");
        }
        elements[++topIndex] = element;
    }

    // Pop an element from the stack
    void pop() {
        if (topIndex < 0) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        --topIndex;
    }

    // Peek at the top element of the stack
    T& top() {
        if (topIndex < 0) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements[topIndex];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topIndex < 0;
    }

    // Get the size of the stack
    size_t size() const {
        return static_cast<size_t>(topIndex + 1);
    }
};

int main() {
    // Create a stack of integers with a maximum size of 10
    Stack<int, 10> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    // Display the top element
    std::cout << "Top element: " << intStack.top() << std::endl;

    // Pop an element
    intStack.pop();
    std::cout << "Top element after pop: " << intStack.top() << std::endl;

    // Check if the stack is empty
    std::cout << "Is stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << std::endl;

    // Display the size of the stack
    std::cout << "Stack size: " << intStack.size() << std::endl;

    return 0;
}
