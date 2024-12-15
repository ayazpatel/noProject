#include <iostream>
using namespace std;

class Counter {
private:
    static int count; // Static data member

public:
    // Constructor increments the static count
    Counter() {
        ++count;
    }

    // Static member function to get the current count
    static int getCount() {
        return count;
    }
};

// Initialize the static data member
int Counter::count = 0;

int main() {
    cout << "Initial count: " << Counter::getCount() << endl;

    Counter c1;
    cout << "Count after creating c1: " << Counter::getCount() << endl;

    Counter c2;
    cout << "Count after creating c2: " << Counter::getCount() << endl;

    Counter c3;
    cout << "Count after creating c3: " << Counter::getCount() << endl;

    return 0;
}
