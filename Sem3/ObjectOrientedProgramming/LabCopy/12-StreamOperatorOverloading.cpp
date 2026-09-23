// Question: Write a C++ program to overload stream insertion (<<) and stream extraction (>>)
// operators to read and display user-defined Time objects.

#include <iostream>
using namespace std;

class Time {
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    friend istream& operator>>(istream& in, Time& t) {
        cout << "Enter hours, minutes, and seconds: ";
        in >> t.hours >> t.minutes >> t.seconds;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Time& t) {
        out << t.hours << "h " << t.minutes << "m " << t.seconds << "s";
        return out;
    }
};

int main() {
    Time t;
    cin >> t;
    cout << "Time: " << t << endl;
    return 0;
}
