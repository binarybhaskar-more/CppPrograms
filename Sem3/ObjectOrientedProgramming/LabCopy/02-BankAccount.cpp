// Question: Define a class to represent a bank account.

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    string name;
    int accNum;
    double balance;

public:
    void init(string n, int a, double b) {
        name = n;
        accNum = a;
        balance = b;
    }

    void deposit(double amount) {
        cout << "Depositing: " << amount << endl;
        balance += amount;
    }

    void withdraw(double amount) {
        cout << "Withdrawing: " << amount << endl;
        if (amount > balance) {
            cout << "Insufficient balance\n";
        } else {
            balance -= amount;
        }
    }

    void display() {
        cout << "Name: " << name << "\nBalance: " << balance << "\n";
    }
};

int main() {
    BankAccount acc;
    acc.init("Additya", 101, 5000);
    acc.deposit(1500);
    acc.display();
    acc.withdraw(2000);
    acc.display();
    return 0;
}
