#include <iostream>
using namespace std;

class ObjectCounter {
private:
    static int count; // Static data member to keep track of the number of objects

public:
    // Constructor increments the static count
    ObjectCounter() {
        ++count;
    }

    // Destructor decrements the static count
    ~ObjectCounter() {
        --count;
    }

    // Static member function to display the current count of objects
    static void showCount() {
        cout << "Number of objects created: " << count << endl;
    }
};

// Initialize the static data member
int ObjectCounter::count = 0;

int main() {
    ObjectCounter::showCount(); // Display initial count

    ObjectCounter obj1;
    ObjectCounter::showCount(); // Display count after creating obj1

    ObjectCounter obj2;
    ObjectCounter::showCount(); // Display count after creating obj2

    {
        ObjectCounter obj3;
        ObjectCounter::showCount(); // Display count after creating obj3
    } // obj3 goes out of scope here

    ObjectCounter::showCount(); // Display count after obj3 is destroyed

    return 0;
}
