#include <iostream>

using namespace std;

class A {
    int a;
public:
    int b;
    void getAB(int x, int y) {
        a = x; b = y;
    }
    int getA() {
        return a;
    }
};

class B : public A {
    int c; // a not derived, b derived as public
public:
    int mul() {
        c = getA() * b;
        return c;
    }
    void display() {
        cout << "a = " << getA() << endl;
        cout << "b = " << b << endl;
        cout << "a*b = " << c << endl;
    }
    // getAB() is derived as public
    // getA() is derived as public
};

class C: private A {
    int c; // a not derived, b derived as private
public:
    int mul() {
        c = getA() * b;
        return c;
    }
    void display() {
        cout << "a = " << getA() << endl;
        cout << "b = " << b << endl;
        cout << "a*b = " << c << endl;
    }
    // getAB() is derived as private
    // getA() is derived as private

    // making public readData() to use getAB() in main
    void readData(int x, int y) {
        getAB(x, y);
    }
};

int main() {
    B child;
    C son;
    child.getAB(3,4);
    child.mul();
    child.display();
    // son.getAB(4,6);  // Not accessible as its derived as private
    son.readData(4,6); // Using readData() to use getAB()
    son.mul();
    son.display();
    return 0;
}