#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    int rollNo;
    string name;
public:
    void getNo(int r, string n) { rollNo = r; name = n; }
};

class Test: virtual public Student {
protected:
    int sub1, sub2;
public:
    void getMarks(int a, int b) { sub1=a; sub2=b; }
};

class Sports: virtual public Student {
protected:
    int score;
public:
    void getData(int a) { score=a; }
};

class Result: public Test, public Sports {
    int total;
public:
    void display()
    {
        total = sub1 + sub2 + score;
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Sub1: " << sub1 << endl;
        cout << "Sub2: " << sub2 << endl;
        cout << "Score: " << score << endl;
        cout << "Total: " << total << endl;
    }
};

int main() {
    Result R;
    R.getNo(28, "Chirag");
    R.getMarks(12, 14);
    R.getData(5);
    R.display();
    return 0;
} 