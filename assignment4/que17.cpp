#include <iostream>
#include <cstdlib> // For malloc and free

class MyClass {
private:
    int data;

public:
    // Constructor
    MyClass(int value = 0) : data(value) {
        std::cout << "Constructor called, data = " << data << std::endl;
    }

    // Destructor
    ~MyClass() {
        std::cout << "Destructor called, data = " << data << std::endl;
    }

    // Overload new operator
    void* operator new(size_t size) {
        std::cout << "Custom new operator called, size = " << size << std::endl;
        void* p = std::malloc(size);
        if (!p) {
            throw std::bad_alloc();
        }
        return p;
    }

    // Overload delete operator
    void operator delete(void* p) {
        std::cout << "Custom delete operator called" << std::endl;
        std::free(p);
    }
};

int main() {
    // Use overloaded new operator
    MyClass* obj = new MyClass(42);

    // Use overloaded delete operator
    delete obj;

    return 0;
}
