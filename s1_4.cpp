#include <iostream>
using namespace std;

class Main {
    private:
        string name;
        int age;
    public:
        Main() {
            this->name = "Alice";
            this->age = 21;
            cout << "Default Constructor Called" << endl;
        }

        Main(string name, int age) {
            this->name = name;
            this->age = age;
            cout << "Parameterized Constructor Called" << endl;
        }

        Main(const Main &obj) {
            this->name = obj.name;
            this->age = obj.age;
            cout << "Copy Constructor Called" << endl;
        }

        void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }

        ~Main() {
            cout << "Destructor Called for " << name << endl;
        }
};

int main() {
    Main m1;
    Main m2("Charlie", 18);
    Main m3 = m2;
    Main* m4;
    m4 = new Main("Bob", 16);

    m1.display();
    m2.display(); // m2 will have undefined state due to move
    m3.display();
    m4->display();
    delete m4;

    return 0;
}
