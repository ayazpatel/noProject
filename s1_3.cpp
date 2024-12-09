#include <iostream>
#include <vector>

using namespace std;

class HugeInteger {
    private:
        // long int array[40];
        vector<long int> array; // Declare vector without initial size

    public:
        bool isZero(long int value) {
            return value == 0;
        }

        void inputHugeInteger(size_t index, long int value) {
            if(isZero(value)) {
                cout << "Value is zero (non-zero values are allowed only)" << endl;
            } else {
                if (index >= array.size()) {
                    array.resize(index + 1); // Resize vector if index is out of current bounds
                }
                array[index] = value;
            }
        }

        void outputHugeInteger() {
            for(size_t i = 0; i < array.size(); i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }

        void addHugeInteger(size_t index, long int value) {
            if(isZero(value)) {
                cout << "Value is zero (non-zero values are allowed only)" << endl;
            } else {
                if (index < array.size()) {
                    array[index] += value;
                } else {
                    cout << "Index out of bounds" << endl;
                }
            }
        }

        void subtractHugeInteger(size_t index, long int value) {
            if(isZero(value)) {
                cout << "Value is zero (non-zero values are allowed only)" << endl;
            } else {
                if (index < array.size()) {
                    array[index] -= value;
                } else {
                    cout << "Index out of bounds" << endl;
                }
            }
        }

        bool isEqualTo(long int value1, long int value2) {
            return value1 == value2;
        }

        bool isNotEqualTo(long int value1, long int value2) {
            return value1 != value2;
        }

        bool isGreaterThan(long int value1, long int value2) {
            return value1 > value2;
        }

        bool isLessThan(long int value1, long int value2) {
            return value1 < value2;
        }

        bool isGreaterThanOrEqualTo(long int value1, long int value2) {
            return value1 >= value2;
        }

        bool isLessThanOrEqualTo(long int value1, long int value2) {
            return value1 <= value2;
        }
};

int main() {
    HugeInteger hugeInteger;
    hugeInteger.inputHugeInteger(0, 100000);
    hugeInteger.inputHugeInteger(1, 200000);
    hugeInteger.inputHugeInteger(2, 300000);
    hugeInteger.inputHugeInteger(3, 400000);
    hugeInteger.inputHugeInteger(4, 500000);

    hugeInteger.outputHugeInteger();

    hugeInteger.addHugeInteger(2, 200000);
    hugeInteger.outputHugeInteger();

    hugeInteger.subtractHugeInteger(4, 100000);
    hugeInteger.outputHugeInteger();

    return 0;
}
