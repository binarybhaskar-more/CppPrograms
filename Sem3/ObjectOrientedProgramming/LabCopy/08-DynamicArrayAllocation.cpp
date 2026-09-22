// Question: Write a C++ program to demonstrate dynamic memory allocation using 'new' and
// 'delete' operators for an array of complex numbers.

#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    void get() {
        cin >> real >> imag;
    }

    void display() {
        cout << real << " + " << imag << "i\n";
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    Complex* arr = new Complex[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter real and imag for number " << i + 1 << ": ";
        arr[i].get();
    }

    cout << "\nComplex Numbers:\n";
    for (int i = 0; i < n; i++) {
        arr[i].display();
    }

    delete[] arr;
    return 0;
}
