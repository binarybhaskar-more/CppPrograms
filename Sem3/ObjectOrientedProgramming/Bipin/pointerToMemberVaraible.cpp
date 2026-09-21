#include <iostream>
#include <string>

using namespace std;

void breakLine() {
    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
}

class Student 
{
public:
    string name;
    int rollNo;
    int marks;

    int *roll = &rollNo;

    Student(void) {};

    Student(string name, int rollNo, int marks) {
        this->name = name;
        (*roll) = rollNo;
        setMarks(marks);
    }

    void setName(string name) { this->name = name; }
    void setMarks(int marks) { this->marks = marks; }

    Student getGreater(Student other) {
        if (other.marks > this->marks) return other;
        return *this;
    };

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "Name:" << s.name << "\n" << "Roll No:" << s.rollNo << "\n" << "Marks:" << s.marks << "\n";
        return out;
    }
};

int main() 
{
    Student bipin;

    Student *bipinPtr = &bipin;
    int Student::*marksPtr = &Student::marks;
    int Student::*rollPtr = &Student::rollNo;

    bipin.setName("Bipin");
    bipin.*rollPtr = 26;
    bipinPtr->*marksPtr = 14;

    Student gaurav("Gaurav", 32, 12);

    breakLine();
    cout << bipin;
    breakLine();
    cout << gaurav;
    breakLine();
    cout << "The student with greater marks is: \n" << bipin.getGreater(gaurav) << "\n";
    breakLine();

    return 0;
}