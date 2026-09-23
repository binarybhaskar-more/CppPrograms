// Question: Write a C++ program to demonstrate type conversions

#include <iostream>
using namespace std;

class Minutes {
    int totalMins;

public:
    // Predefined to User-defined (via constructor)
    Minutes(int m = 0) : totalMins(m) {}

    // User-defined to Predefined (via operator overloading)
    operator int() { 
        return totalMins;
    }

    int getMins() {
        return totalMins;
    }

    void display() {
        cout << totalMins << " mins\n";
    }
};

class HoursMinutes {
    int hr, min;

public:
    HoursMinutes(int h = 0, int m = 0) : hr(h), min(m) {}

    // User-defined to User-defined (via constructor)
    HoursMinutes(Minutes m) {
        hr = m.getMins() / 60;
        min = m.getMins() % 60;
    }

    // User-defined to User-defined (via operator overloading)
    operator Minutes() {
        return Minutes(hr * 60 + min);
    }

    void display() {
        cout << hr << " hrs " << min << " mins\n";
    }
};

int main() {
    Minutes m1 = 135;
    cout << "Predefined to User-defined (Constructor): ";
    m1.display();

    int rawMins = m1;
    cout << "User-defined to Predefined (Operator): " << rawMins << endl;

    HoursMinutes hm1 = m1;
    cout << "User-defined to User-defined (Constructor): ";
    hm1.display();

    HoursMinutes hm2(2, 30);
    Minutes m2 = hm2;
    cout << "User-defined to User-defined (Operator): ";
    m2.display();

    return 0;
}
