#include <iostream>
#include <vector>

template <typename T>
class Queue {
private:
    std::vector<T> elements;

public:
    // Enqueue operation to add an element to the queue
    void enqueue(const T& element) {
        elements.push_back(element);
    }

    // Dequeue operation to remove an element from the queue
    void dequeue() {
        if (!isEmpty()) {
            elements.erase(elements.begin());
        } else {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
        }
    }

    // Method to check if the queue is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Method to get the front element of the queue
    T front() const {
        if (!isEmpty()) {
            return elements.front();
        } else {
            throw std::out_of_range("Queue is empty. No front element.");
        }
    }

    // Method to get the size of the queue
    size_t size() const {
        return elements.size();
    }
};

int main() {
    // Create a queue of integers
    Queue<int> intQueue;

    // Enqueue elements
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    // Display the front element
    std::cout << "Front element: " << intQueue.front() << std::endl;

    // Dequeue an element
    intQueue.dequeue();

    // Display the front element after dequeue
    std::cout << "Front element after dequeue: " << intQueue.front() << std::endl;

    // Display the size of the queue
    std::cout << "Queue size: " << intQueue.size() << std::endl;

    return 0;
}
