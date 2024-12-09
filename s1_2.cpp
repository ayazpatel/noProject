#include <iostream>
using namespace std;

class Rectangle {
    private:
        float length = 1.0;
        float width = 1.0;
        float x1, x2, y1, y2;
    public:
        void setCoordinates(float x1, float y1, float x2, float y2) {
            if(x1 > 0.0 && x1 < 20.0) {
                this->x1 = x1;
            } else {
                cout << "x1: value smaller than 0 or greater than 20" << endl;
            }
            if(y1 > 0.0 && y1 < 20.0) {
                this->y1 = y1;
            } else {
                cout << "y1: value smaller than 0 or greater than 20" << endl;
            }
            if(x2 > 0.0 && x2 < 20.0) {
                this->x2 = x2;
            } else {
                cout << "x2: value smaller than 0 or greater than 20" << endl;
            }
            if(y2 > 0.0 && y2 < 20.0) {
                this->y2 = y2;
            } else {
                cout << "y2: value smaller than 0 or greater than 20" << endl;
            }
            calcLength();
            calcWidth();
        }
        
        void calcLength() {
            length = (x1 > x2) ? x1 : x2;
        }
        
        void calcWidth() {
            width = (y1 > y2) ? y1 : y2;
        }
        
        float calcPerimeter() {
            return 2 * (length + width);
        }
        
        float calcArea() {
            return length * width;
        }
        
        bool isSquare() {
            return length == width;
        }
};

int main() {
    Rectangle rect;
    rect.setCoordinates(1.0, 9.0, 1.0, 9.0);

    float resultPerimeter = rect.calcPerimeter();
    float resultArea = rect.calcArea();

    cout << "Perimeter: " << resultPerimeter << endl;
    cout << "Area: " << resultArea << endl;

    if (rect.isSquare()) {
        cout << "The rectangle is also a square." << endl;
    } else {
        cout << "The rectangle is not a square." << endl;
    }

    return 0;
}
