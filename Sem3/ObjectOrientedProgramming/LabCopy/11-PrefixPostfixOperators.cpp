// Question: Write a C++ program to overload unary increment (++) and decrement (--)
// operators in both prefix and postfix forms for a Page class.

#include <iostream>
using namespace std;

class Page {
    int pageNo;

public:
    Page(int p = 1) : pageNo(p) {}

    Page& operator++() {
        ++pageNo;
        return *this;
    }

    Page operator++(int) {
        Page temp = *this;
        pageNo++;
        return temp;
    }

    Page& operator--() {
        --pageNo;
        return *this;
    }

    Page operator--(int) {
        Page temp = *this;
        pageNo--;
        return temp;
    }

    void display() {
        cout << "Page: " << pageNo << endl;
    }
};

int main() {
    Page p(10);

    ++p;
    cout << "Prefix ++: ";
    p.display();

    p++;
    cout << "Postfix ++: ";
    p.display();

    --p;
    cout << "Prefix --: ";
    p.display();

    p--;
    cout << "Postfix --: ";
    p.display();

    return 0;
}
