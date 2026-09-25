// Question: Write a C++ program to demonstrate operator overloading by overloading
// unary minus (-), binary addition (+), and binary subtraction (-) for a Complex class.

#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex operator-() {
        return Complex(-real, -imag);
    }

    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i\n";
    }
};

int main() {
    Complex c1(5, 3), c2(2, 4);

    cout << "c1: ";
    c1.display();
    cout << "c2: ";
    c2.display();

    Complex sum = c1 + c2;
    cout << "c1 + c2: ";
    sum.display();

    Complex diff = c1 - c2;
    cout << "c1 - c2: ";
    diff.display();

    Complex neg = -c1;
    cout << "-c1: ";
    neg.display();

    return 0;
}
