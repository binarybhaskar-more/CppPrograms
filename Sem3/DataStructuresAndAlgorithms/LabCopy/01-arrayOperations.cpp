#include <iostream>
using namespace std;

int main() {
    int arr[10];
    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}