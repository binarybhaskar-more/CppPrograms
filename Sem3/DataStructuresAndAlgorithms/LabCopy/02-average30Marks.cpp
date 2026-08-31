#include <iostream>
using namespace std;

int main() {
    int marks[30];
    float sum = 0;
    cout << "Enter marks of 30 students: ";
    for (int i = 0; i < 30; i++) {
        cin >> marks[i];
    }
    for (int i = 0; i < 30; i++) {
        sum += marks[i];
    }
    cout << "Average marks: " << sum / 30 << "\n";
    return 0;
}