// Question: Create a class Time to store time in hours and minutes and a function to add two Time objects.

#include <iostream>
using namespace std;

class Time {
    int hours, minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    void getTime() {
        cout << "Enter hours and minutes: ";
        cin >> hours >> minutes;
    }

    Time sum(Time t2) {
        Time t;
        t.minutes = minutes + t2.minutes;
        t.hours = hours + t2.hours + t.minutes / 60;
        t.minutes %= 60;
        return t;
    }

    void display() {
        cout << hours << " hrs " << minutes << " mins\n";
    }
};

int main() {
    Time t1, t2, t3;
    t1.getTime();
    t2.getTime();

    t3 = t1.sum(t2);

    cout << "Time 1: ";
    t1.display();
    cout << "Time 2: ";
    t2.display();
    cout << "Sum: ";
    t3.display();

    return 0;
}
