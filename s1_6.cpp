#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Main {
    private:
        vector<int> collection;
    public:
        Main(const vector<int>& collection) {
            this->collection = collection;
        }

        int operator[](size_t index) {
            if(index >= 3) {
                throw out_of_range("Index allowed: 0, 1, 2");
            }
            sortCollection();
            return collection[index];
        }

        void sortCollection() {
            sort(collection.begin(), collection.end(), greater<int>());
        }

        void display() {
            for(size_t i = 0; i<collection.size(); i++) {
                cout << collection[i] << " ";
            }
            cout << endl;
        }
};


int main() {
    vector<int> arr = {10,20,30};
    Main m(arr);
    m.display();
    cout << m[0] << endl;
    cout << m[1] << endl;
    cout << m[2] << endl;
    return 0;
}