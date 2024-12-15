#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a node in sorted order
    void insertSorted(int value) {
        Node* newNode = new Node(value);
        if (!head || head->data >= value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Overload + operator to insert a node in sorted order
    LinkedList& operator+(int value) {
        insertSorted(value);
        return *this;
    }

    // Function to print the linked list
    void printList() const {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;
    list + 5;
    list + 3;
    list + 10;
    list + 1;
    list.printList(); // Output: 1 -> 3 -> 5 -> 10 -> nullptr

    return 0;
}

/*
Certainly! Let's go through the `que2.cpp` program step by step to understand how it works.

### Overview

The program defines a `LinkedList` class that supports inserting nodes in sorted order. It demonstrates the use of operator overloading to insert nodes into the linked list using the `+` operator.

### Code Breakdown

```cpp
#include <iostream>
using namespace std;
```
- These lines include the iostream library, which is necessary for input and output operations, and use the standard namespace.

```cpp
// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
```
- A `Node` structure is defined to represent each element in the linked list.
- It contains an integer `data` and a pointer `next` to the next node.
- The constructor initializes `data` with the given value and sets `next` to `nullptr`.

```cpp
// LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}
```
- The `LinkedList` class is defined with a public member `head`, which points to the first node in the list.
- The constructor initializes `head` to `nullptr`, indicating an empty list.

```cpp
    // Function to insert a node in sorted order
    void insertSorted(int value) {
        Node* newNode = new Node(value);
        if (!head || head->data >= value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
```
- The `insertSorted` function inserts a new node with the given `value` into the list in sorted order.
- If the list is empty or the new value is smaller than the head's data, the new node becomes the new head.
- Otherwise, it traverses the list to find the correct position and inserts the new node there.

```cpp
    // Overload + operator to insert a node in sorted order
    LinkedList& operator+(int value) {
        insertSorted(value);
        return *this;
    }
```
- The `+` operator is overloaded to allow inserting a node into the list using the `+` operator.
- It calls `insertSorted` to perform the insertion and returns the modified list.

```cpp
    // Function to print the linked list
    void printList() const {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};
```
- The `printList` function prints the elements of the linked list.
- It iterates over each node, printing its data, and ends with "nullptr" to indicate the end of the list.

```cpp
int main() {
    LinkedList list;
    list + 5;
    list + 3;
    list + 10;
    list + 1;
    list.printList(); // Output: 1 -> 3 -> 5 -> 10 -> nullptr

    return 0;
}
```
- The `main` function creates a `LinkedList` object `list`.
- It uses the overloaded `+` operator to insert values `5`, `3`, `10`, and `1` into the list in sorted order.
- Finally, it calls `printList` to display the sorted list.

### Summary

This program demonstrates how to use operator overloading to simplify the insertion of nodes into a linked list in sorted order. It provides a clear example of how to manage dynamic data structures in C++.
*/