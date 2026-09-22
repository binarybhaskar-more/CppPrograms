// Question: Write a C++ program with USD and INR classes to find the greater currency
// value using a friend function (1 USD = 95 INR).

#include <iostream>
using namespace std;

class INR;

class USD {
    float amount;

public:
    USD(float a = 0) : amount(a) {}

    void display() {
        cout << "$" << amount << endl;
    }

    friend void findMax(USD, INR);
};

class INR {
    float amount;

public:
    INR(float a = 0) : amount(a) {}

    void display() {
        cout << "Rs. " << amount << endl;
    }

    friend void findMax(USD, INR);
};

void findMax(USD u, INR i) {
    float usdInInr = u.amount * 95;
    if (usdInInr > i.amount) {
        cout << "$" << u.amount << " is greater than Rs. " << i.amount << endl;
    } else if (i.amount > usdInInr) {
        cout << "Rs. " << i.amount << " is greater than $" << u.amount << endl;
    } else {
        cout << "Both amounts are equal" << endl;
    }
}

int main() {
    USD u(50);
    INR i(4500);

    findMax(u, i);
    return 0;
}
