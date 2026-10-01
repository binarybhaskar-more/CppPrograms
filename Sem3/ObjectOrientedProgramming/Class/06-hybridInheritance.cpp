#include <iostream>

using namespace std;

class Student {
protected:
    int rollNo;
public:
    void getNo(int a) { rollNo = a; }
};

class Marks : public Student {
protected:
    int sub1, sub2;
public:
    void getMarks(int s1, int s2) { sub1 = s1; sub2 = s2;}
};

class Sports {
protected:
    int score;
public:
    void getScore(int s) { score = s; }
};

class Result : public Marks, public Sports {
    int total;
public:
    void display() {
        total = sub1 + sub2 + score;
        cout << "Roll No: " << rollNo << endl;
        cout << "Sub 1 Marks: " << sub1 << endl;
        cout << "Sub 2 Marks: " << sub2 << endl;
        cout << "Score: " << score << endl;
        cout << "Total: " << total << endl;
    }
};

int main() {
    Result aman;
    aman.getNo(101);
    aman.getMarks(14,15);
    aman.getScore(12);
    aman.display();
    return 0;
}