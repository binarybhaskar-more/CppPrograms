#include <iostream>

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    for (int i = 2; i <= num; ++i) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
    return 0;
}