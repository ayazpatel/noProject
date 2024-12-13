#include <iostream>
using namespace std;

class RationalNumber {
private:
    int numerator;
    int denominator;

    // Helper function to calculate the greatest common divisor (GCD)
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper function to reduce the fraction
    void reduce() {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
    }

    // Helper function to ensure the denominator is positive
    void ensurePositiveDenominator() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor
    RationalNumber(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        ensurePositiveDenominator();
        reduce();
    }

    // Overload addition operator
    RationalNumber operator+(const RationalNumber& rhs) const {
        int num = numerator * rhs.denominator + rhs.numerator * denominator;
        int denom = denominator * rhs.denominator;
        return RationalNumber(num, denom);
    }

    // Overload subtraction operator
    RationalNumber operator-(const RationalNumber& rhs) const {
        int num = numerator * rhs.denominator - rhs.numerator * denominator;
        int denom = denominator * rhs.denominator;
        return RationalNumber(num, denom);
    }

    // Overload multiplication operator
    RationalNumber operator*(const RationalNumber& rhs) const {
        int num = numerator * rhs.numerator;
        int denom = denominator * rhs.denominator;
        return RationalNumber(num, denom);
    }

    // Overload division operator
    RationalNumber operator/(const RationalNumber& rhs) const {
        if (rhs.numerator == 0) {
            throw invalid_argument("Cannot divide by zero.");
        }
        int num = numerator * rhs.denominator;
        int denom = denominator * rhs.numerator;
        return RationalNumber(num, denom);
    }

    // Overload equality operator
    bool operator==(const RationalNumber& rhs) const {
        return numerator == rhs.numerator && denominator == rhs.denominator;
    }

    // Overload inequality operator
    bool operator!=(const RationalNumber& rhs) const {
        return !(*this == rhs);
    }

    // Overload less than operator
    bool operator<(const RationalNumber& rhs) const {
        return numerator * rhs.denominator < rhs.numerator * denominator;
    }

    // Overload greater than operator
    bool operator>(const RationalNumber& rhs) const {
        return rhs < *this;
    }

    // Overload less than or equal to operator
    bool operator<=(const RationalNumber& rhs) const {
        return !(*this > rhs);
    }

    // Overload greater than or equal to operator
    bool operator>=(const RationalNumber& rhs) const {
        return !(*this < rhs);
    }

    // Function to display the rational number
    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    try {
        RationalNumber r1(3, 4);
        RationalNumber r2(2, 5);

        RationalNumber sum = r1 + r2;
        RationalNumber diff = r1 - r2;
        RationalNumber prod = r1 * r2;
        RationalNumber quot = r1 / r2;

        cout << "r1: "; r1.display();
        cout << "r2: "; r2.display();
        cout << "Sum: "; sum.display();
        cout << "Difference: "; diff.display();
        cout << "Product: "; prod.display();
        cout << "Quotient: "; quot.display();

        cout << "r1 == r2: " << (r1 == r2) << endl;
        cout << "r1 != r2: " << (r1 != r2) << endl;
        cout << "r1 < r2: " << (r1 < r2) << endl;
        cout << "r1 > r2: " << (r1 > r2) << endl;
        cout << "r1 <= r2: " << (r1 <= r2) << endl;
        cout << "r1 >= r2: " << (r1 >= r2) << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
