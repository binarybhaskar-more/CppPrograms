#include <iostream>

using namespace std;

class Student {
protected:
    int rollNo;
public:
    void getNo(int a) {
        rollNo = a;
    }
    void putNo() {
        cout << "Roll No: " << rollNo << endl;
    }
    void display() { putNo(); }
};

class Marks : public Student {
protected:
    float sub1, sub2;
    // rollNo is available as protected member
public:
    void getMarks(float m1, float m2) {
        sub1 = m1;
        sub2 = m2;
    }
    void putMarks() {
        cout << "Marks in Sub1: " << sub1 << endl;
        cout << "Marks in Sub2: " << sub2 << endl;
    }
    void display() { putMarks(); }
    // getNo() and putNo() are available as public members
    // display() is overridden to display marks instead of roll number
};

class Result : public Marks {
    float total;
    // rollNo, sub1, and sub2 are available as protected members
public:
    void display() {
        total = sub1 + sub2;
        Student::display(); Marks::display(); // Using scope resolution operator to call display() of Student and Marks classes
        cout << "Total: " << total << endl;
    }
    // getNo(), putNo(), getMarks(), and putMarks() are available as public members
    // display() is overridden to display roll number, marks, and total
};

int main() {
    Result r;
    r.getNo(101);
    r.getMarks(72.5, 82.4);
    r.display();
    return 0;
}