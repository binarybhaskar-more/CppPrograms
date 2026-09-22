// Question: Write a C++ program to create a Complex class representing complex numbers.
// Demonstrate the use of default constructor, parameterized constructor and copy constructor

#include <iostream>
using namespace std;

class Complex {
    float real, imag;
public:
    Complex() : real(0), imag(0) {
        cout << real << " + " << imag << "i : created by Default constructor\n";
    }

    Complex(float r, float i) : real(r), imag(i) {
        cout << real << " + " << imag << "i : created by Parameterized constructor\n";
    }

    Complex(const Complex& c) : real(c.real), imag(c.imag) {
        cout << real << " + " << imag << "i : created by Copy constructor\n";
    }
};

int main() {
    Complex c1;
    Complex c2(3, 4);
    Complex c3 = c2;
    return 0;
}
