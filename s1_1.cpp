#include <iostream>
using namespace std;

class Rectangle {
    private:
        float length = 1;
        float width = 1;
    public:
        float calcPerimeter() {
            return 2 * (length + width);
        }
        float calcArea() {
            return length * width;
        }
        void setLength(float length) {
            if(length > 0.0 && length < 20.0) {
                this->length = length;
            }
        }
        float getLength() {
            return length;
        }
        void setWidth(float width) {
            if(width > 0.0 && width < 20.0) {
                this->width = width;
            }
        }
        float getWidth() {
            return width;
        }
};

int main() {
    Rectangle rect;
    rect.setLength(15.55);
    rect.setWidth(18.66);

    float w = rect.getWidth();
    float l = rect.getLength();
    cout << "Length: " << l << endl;
    cout << "Width: " << w << endl;

    float resultPerimeter = rect.calcPerimeter();
    float resultArea = rect.calcArea();

    cout << "Perimeter: " << resultPerimeter << endl;
    cout << "Area: " << resultArea << endl;

    return 0;
}
