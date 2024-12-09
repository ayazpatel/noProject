#include <iostream>
using namespace std;

class Date {
    private:
        int day;
        int month;
        int year;

    public:
        // Default constructor
        Date() {
            this->day = 30;
            this->month = 2;
            this->year = 2024;
        }

        // Custom constructor
        Date(int day, int month, int year) {
            this->day = day;
            this->month = month;
            this->year = year;
        }

        // Overload the + operator to add days
        Date operator + (int value) {
            Date obj(day, month, year);
            obj.day += value;
            
            while(obj.day > 30) {
                obj.day -= 30;
                obj.month++;
                if(obj.month > 12) {
                    obj.month = 1;
                    obj.year++;
                }
            }

            return obj;
        }

        // Overload the - operator to subtract days
        Date operator - (int value) {
            Date obj(day, month, year);
            obj.day -= value;
            
            while(obj.day <= 0) {
                obj.month--;
                if(obj.month <= 0) {
                    obj.month = 12;
                    obj.year--;
                }
                obj.day += 30;
            }

            return obj;
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

    return 0;
}
