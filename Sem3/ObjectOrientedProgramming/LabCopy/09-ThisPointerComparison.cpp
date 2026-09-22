// Question: Write a C++ program to compare two persons by age and return the older person using the 'this' pointer.

#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    int age;

public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    Person& older(Person& p) {
        if (p.age > this->age) return p;
        return *this;
    }

    void display() {
        cout << name << " (" << age << ")\n";
    }
};

int main() {
    Person p1("Alice", 21), p2("Bob", 25);
    Person res = p1.older(p2);
    cout << "Older: ";
    res.display();
    return 0;
}
