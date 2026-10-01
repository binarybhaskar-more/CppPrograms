#include <iostream>

using namespace std;

class xyz {
private:
    int a; // not inheritable
protected:
    int b; // inheritable but not visible to outside the class
public:
    int c; // inheritable and visible to outside the class

    xyz(int a = 10, int b = 20, int c = 30) : a(a), b(b), c(c) {}
    void display() {
        cout << a << " " << b << " " << c << endl;
    }
};

class abc : public xyz {
    // a is not inherited
    // b is inherited but not visible to outside the class
    // c is inherited and visible to outside the class
public:
    void display() {
        cout << "a is not inherited" << endl;
        cout << b << " " << c << endl;
    }
};

class pqr : protected xyz {
    // a is not inherited
    // b and c are inherited but not visible to outside the class
public:
    void display() {
        cout << "a is not inherited" << endl;
        cout << b << " " << c << endl;
    }
};

int main () {
    xyz xObj;
    xObj.display();

    abc aObj;
    aObj.display();
    cout << "c is accessible directly in aObj: " << aObj.c << endl;

    pqr pObj;
    pObj.display();
    // cout << "Accessing c directly in pObj: " << pObj.c << endl; // This will cause an error
    return 0;
}