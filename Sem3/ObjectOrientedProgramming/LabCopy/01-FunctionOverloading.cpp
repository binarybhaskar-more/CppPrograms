// Question: Write a C++ program to calculate the volume of different geometric shapes
// (Cube, Cylinder, and Cuboid) using function overloading.

#include <iostream>
using namespace std;

float volume(float s) {
    return s * s * s;
}

float volume(float r, float h) {
    return 3.14 * r * r * h;
}

float volume(float l, float b, float h) {
    return l * b * h;
}

int main() {
    float s, r, h, l, b;
    cout << "Enter side of cube: ";
    cin >> s;
    cout << "Volume of cube: " << volume(s) << endl;

    cout << "Enter radius and height of cylinder: ";
    cin >> r >> h;
    cout << "Volume of cylinder: " << volume(r, h) << endl;

    cout << "Enter length, breadth and height of cuboid: ";
    cin >> l >> b >> h;
    cout << "Volume of cuboid: " << volume(l, b, h) << endl;

    return 0;
}
