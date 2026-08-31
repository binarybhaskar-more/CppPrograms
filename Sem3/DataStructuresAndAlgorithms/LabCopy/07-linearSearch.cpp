#include <iostream>
using namespace std;

int main() {
    int arr[10];
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    int tar;
    cout << "Enter the number to search: ";
    cin >> tar;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == tar) {
            cout << "Number found at index: " << i << "\n";
            return 0;
        }
    }
    cout << "Number not found in the array." << "\n";
    return 0;
}