// Question: Write a C++ program to overload unary minus (-) operator for a Complex class.

#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex operator-() {
        return Complex(-real, -imag);
    }

    void display() {
        cout << real << " + " << imag << "i\n";
    }
};

int main() {
    Complex c(3, -4);
    cout << "Original: ";
    c.display();

    Complex neg = -c;
    cout << "Negated: ";
    neg.display();

    return 0;
}
