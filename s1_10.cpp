#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor
    Date() : day(30), month(2), year(2024) {}

    // Custom constructor
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    // Overload the + operator to add days
    Date operator+(int value) const {
        Date obj(day, month, year);
        obj.day += value;
        
        while (obj.day > 30) {
            obj.day -= 30;
            obj.month++;
            if (obj.month > 12) {
                obj.month = 1;
                obj.year++;
            }
        }

        return obj;
    }

    // Overload the - operator to subtract days
    Date operator-(int value) const {
        Date obj(day, month, year);
        obj.day -= value;
        
        while (obj.day <= 0) {
            obj.month--;
            if (obj.month <= 0) {
                obj.month = 12;
                obj.year--;
            }
            obj.day += 30;
        }

        return obj;
    }

    // Overload the = operator
    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    // Overload the < operator
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    // Overload the <= operator
    bool operator<=(const Date& other) const {
        return *this < other || *this == other;
    }

    // Overload the > operator
    bool operator>(const Date& other) const {
        return !(*this <= other);
    }

    // Overload the >= operator
    bool operator>=(const Date& other) const {
        return !(*this < other);
    }

    // Overload the == operator for comparison
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    // Overload the ++ operator (prefix)
    Date& operator++() {
        *this = *this + 1;
        return *this;
    }

    // Overload the ++ operator (postfix)
    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    // Overload the -- operator (prefix)
    Date& operator--() {
        *this = *this - 1;
        return *this;
    }

    // Overload the -- operator (postfix)
    Date operator--(int) {
        Date temp = *this;
        --(*this);
        return temp;
    }

    // Function to display the date
    void display() const {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date date(15, 7, 2024);
    Date newDateAdd = date + 30;
    Date newDateSub = date - 20;

    cout << "Original Date: ";
    date.display();
    cout << "New Date After Adding 30 Days: ";
    newDateAdd.display();
    cout << "New Date After Subtracting 20 Days: ";
    newDateSub.display();

    // Demonstrate assignment chaining
    Date a, b, c, d;
    a = b = c = d = date;
    cout << "Chained Assignment Date: ";
    a.display();

    // Demonstrate comparison
    if (newDateAdd > newDateSub) {
        cout << "New Date After Adding is greater than New Date After Subtracting" << endl;
    }

    // Demonstrate increment and decrement
    ++date;
    cout << "Date after prefix increment: ";
    date.display();

    date++;
    cout << "Date after postfix increment: ";
    date.display();

    --date;
    cout << "Date after prefix decrement: ";
    date.display();

    date--;
    cout << "Date after postfix decrement: ";
    date.display();

    return 0;
}
