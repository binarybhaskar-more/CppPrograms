// Question: Write a C++ program to demonstrate the use of static data members and static
// member functions to track the number of current students.

#include <iostream>
#include <string>
using namespace std;

class Student {
    int rollNo;
    string name;
    static int count;

public:
    Student(int r, string n) : rollNo(r), name(n) {
        count++;
    }

    ~Student() {
        count--;
    }

    void display() {
        cout << "Roll no." << rollNo << " : " << name << endl;
    }

    static int getCount() {
        return count;
    }
};

int Student::count = 0;

int main() {
    Student s1(1, "Ayush");
    Student s2(2, "Bipin");

    s1.display();
    s2.display();
    cout << "Students: " << Student::getCount() << endl;

    {
        Student s3(3, "Gaurav");
        s3.display();
        cout << "Students: " << Student::getCount() << endl;
    }

    cout << "Left the Gaurav block." << endl;

    cout << "Students: " << Student::getCount() << endl;
    return 0;
}
