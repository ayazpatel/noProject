#include <iostream>
#include <fstream>
#include <string>
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

    // Load the linked list from a file using an absolute path
    void loadFromFile(const string& absolutePath) {
        ifstream inFile(absolutePath);
        if (!inFile) {
            cerr << "Error opening file for reading." << endl;
            return;
        }
        int value;
        while (inFile >> value) {
            *this + value; // Use overloaded + operator to insert
        }
        inFile.close();
        cout << "List loaded from " << absolutePath << endl;
    }
};

int main() {
    LinkedList list;
    string absolutePath;

    cout << "Enter the full absolute path of the file to load: ";
    cin >> absolutePath;

    list.loadFromFile(absolutePath);
    list.printList();

    return 0;
}
