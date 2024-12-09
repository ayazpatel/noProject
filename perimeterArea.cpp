#include <iostream>
using namespace std;

template <typename T>
void disp(const string& message, const T& arg) {
    cout << message << ": " << arg << endl;
}

template <typename T>
void input(T& arg) {
    cin >> arg;
}

struct rect {
    float x1, x2, y1, y2;
};

int main() {
    rect r;
    cout << "x1: ";
    input(r.x1);
    cout << "x2: ";
    input(r.x2);
    cout << "y1: ";
    input(r.y1);
    cout << "y2: ";
    input(r.y2);

    cout << "Entered Values are:" << endl;
    disp("x1", r.x1);
    disp("x2", r.x2);
    disp("y1", r.y1);
    disp("y2", r.y2);

    float differenceX = (r.x1 >= r.x2) ? (r.x1 - r.x2) : (r.x2 - r.x1);
    float differenceY = (r.y1 >= r.y2) ? (r.y1 - r.y2) : (r.y2 - r.y1);

	disp("Difference X", differenceX);
	disp("Difference Y", differenceY);

//	float perimeterResult = (r.x1 + r. y1) * (r.x2 + r.y2);
    float perimeterResult = 2 * (differenceX + differenceY);
    float areaResult = differenceX * differenceY;
	
	disp("Perimeter (Answer)", perimeterResult);
	disp("Area (Answer)", areaResult);

    return 0;
}
