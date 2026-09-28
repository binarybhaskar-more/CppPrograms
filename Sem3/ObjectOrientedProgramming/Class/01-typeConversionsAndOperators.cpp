#include <iostream>

using namespace std;

class mins {
    int val;
public:
    mins() {}

    // Using constructor to convert int to mins
    mins(int v) : val(v) {}

    // Using operator overloading to convert mins to int
    operator int() {
        return val;
    }

    friend mins operator*(int x, const mins& m) {
        return mins(x * m.val);
    }

    friend class hrmin;

    friend std::ostream& operator<<(std::ostream& out, const mins& m) {
        out << m.val << " minutes";
        return out;
    }
};

class hrmin {
    int hr;
    int min;
public:
    hrmin() {}
    hrmin(int h, int m) : hr(h), min(m) {}

    // Using constructor to convert mins to hrmin
    hrmin(mins m) {
        hr = m.val / 60;
        min = m.val % 60;
    }

    // Using operator overloading to convert hrmin to mins
    operator mins() {
        return mins(hr * 60 + min);
    }

    friend hrmin operator*(int x, const hrmin& h) {
        return hrmin(x * mins(h.hr * 60 + h.min));
    }

    friend std::ostream& operator<<(std::ostream& out, const hrmin& h) {
        out << h.hr << " hours and " << h.min << " minutes";
        return out;
    }
};

int main() {
    mins m;
    m = 125;

    hrmin hm = m; // Implicit conversion from mins to hrmin

    cout << "Minutes: " << m << std::endl;
    cout << "Hours and Minutes: " << hm << std::endl;
    cout << "Twice of Hours and Minutes: " << 2 * hm << std::endl;

    return 0;
}