#include<iostream>
using namespace std;

class A {
    int a;
public:
    int b;

    void getab(int x, int y) { a=x; b=y; }
    int geta() { return a; }
    int getb() { return b; }
};

class B: public A {
    int c;
    public:

    int mul() {
        c = geta() * b;
        return c;
    }
    void display() {
        cout<<"a="<<geta()<<endl;
        cout<<"b="<<b<<endl;
        cout<<"a*b";
    }
};

int main() {
    
    B b;
    b.getab(5, 10);
    b.mul();
    b.display();
    return 0;
}