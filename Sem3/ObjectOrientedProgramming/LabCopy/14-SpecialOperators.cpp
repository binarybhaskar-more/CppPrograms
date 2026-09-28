// Question: Write a C++ program to overload the subscript, function call and comma operators

#include <iostream>
#include <string>

using namespace std;

class Results {
    string name;
    int math, oops, dsa;
public:
    Results(
        string n = "",
        int m = 0,
        int o = 0,
        int d = 0
    ): name(n), math(m), oops(o), dsa(d) {}

    void operator()() {
        cout << name << " says hello!" << endl;
    }

    int operator[](int index) {
        switch (index) {
            case 0: return math;
            case 1: return oops;
            case 2: return dsa;
            default: return -1;
        }
    }

    int operator,(int index) {
        return (*this)[index];
    }
};

int main() {
    Results gaurav("Gaurav", 12, 13, 14);
    gaurav();
    cout << "Gaurav's marks in Math: " << gaurav[0] << endl;
    cout << "Gaurav's marks in OOPs: " << (gaurav, 2) << endl;
}