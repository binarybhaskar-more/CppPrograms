#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int rollno;
    string name;

    Student(int rollno, string name) : rollno(rollno), name(name) {};
    int getRollno() { return rollno; }
    string getName() { return name; }
};

int main() {
    // Pointer to Member Variables
    int Student::*ptrRollno = &Student::rollno;
    string Student::*ptrName = &Student::name;

    // Pointer to Member Functions
    int (Student::*ptrGetRollno)() = &Student::getRollno;
    string (Student::*ptrGetName)() = &Student::getName;

    Student naina(43, "Naina");
    Student *unknown = &naina;

    // Using the pointers to access member variables and functions
    cout << "Using pointer to member variables" << endl;
    cout << naina.*ptrRollno << endl;
    cout << naina.*ptrName << endl;

    cout << "Using pointer to member functions WITH pointer to object" << endl;
    cout << (*unknown.*ptrGetRollno)() << endl;
    cout << (*unknown.*ptrGetName)() << endl;

    cout << "Using only pointer to object" << endl;
    cout << unknown->getRollno() << endl;
    cout << unknown->getName() << endl;
    return 0;
}