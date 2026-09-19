#include <iostream>

using namespace std;

class A {
    int a, b;
public:
    void getData() {
        cout << "A: " << a << ", B: " << b << "\n";
    }
    void getA() {
        cout << "A: " << a << "\n";
    }
};

class B : public A {
    
};

int main() {
    return 0;
}