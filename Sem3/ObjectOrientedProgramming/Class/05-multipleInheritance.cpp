#include <iostream>

using namespace std;

class M {
protected:
    int m;
public:
    void getM(int a) { m = a; }
};

class N {
protected:
    int n;
public:
    void getN(int b) { n = b; }
};

class P : public M, public N {
    int p;
public:
    void display() {
        p = m * n;
        cout << "m = " << m << endl;
        cout << "n = " << n << endl;
        cout << "m * n = " << p << endl;
    }
};

int main() {
    P x;
    x.getM(10);
    x.getN(5);
    x.display();
    return 0;
}
