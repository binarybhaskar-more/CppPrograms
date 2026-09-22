// Question: Write a C++ program to implement a Shopping Cart system using classes,
// static variables, and switch cases.

#include <iostream>
#include <string>
using namespace std;

class Item {
    int itemCode;
    string name;
    float price;
    int cartQty;

public:
    static float totalPrice;

    void addItem() {
        cout << "Enter item code, name, and price: ";
        cin >> itemCode >> name >> price;
        cartQty = 0;
    }

    void addToCart(int qty) {
        cartQty += qty;
        totalPrice += price * qty;
    }

    void removeFromCart(int qty) {
        if (qty > cartQty) qty = cartQty;
        totalPrice -= price * qty;
        cartQty -= qty;
    }

    void showItem() {
        if (cartQty > 0) {
            cout << itemCode << "\t" << name << "\t" << price << "\t" << cartQty << "\t" << price * cartQty << "\n";
        }
    }

    void clear() {
        totalPrice -= price * cartQty;
        cartQty = 0;
    }

    int getCode() {
        return itemCode;
    }

    static void showBill() {
        cout << "Total Bill: " << totalPrice << "\n";
    }

    static void clearBill() {
        totalPrice = 0;
    }
};

float Item::totalPrice = 0;

int main() {
    Item items[50];
    int count = 0;
    int choice;

    do {
        cout << "\n0. Initialise cart\n1. Add Item\n2. Remove Item\n3. Show Bill\n4. Clear Cart\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                for (int i = 0; i < count; i++) {
                    items[i].clear();
                }
                Item::clearBill();
                count = 0;
                cout << "Cart initialised.\n";
                break;

            case 1: {
                int qty;
                items[count].addItem();
                cout << "Enter quantity: ";
                cin >> qty;
                items[count].addToCart(qty);
                count++;
                break;
            }

            case 2: {
                int code, qty;
                cout << "Enter item code to remove: ";
                cin >> code;
                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (items[i].getCode() == code) {
                        cout << "Enter quantity to remove: ";
                        cin >> qty;
                        items[i].removeFromCart(qty);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Item not found in cart.\n";
                break;
            }

            case 3:
                cout << "Code\tName\tPrice\tQty\tTotal\n";
                for (int i = 0; i < count; i++) {
                    items[i].showItem();
                }
                Item::showBill();
                break;

            case 4:
                for (int i = 0; i < count; i++) {
                    items[i].clear();
                }
                Item::clearBill();
                count = 0;
                cout << "Cart cleared.\n";
                break;

            case 5:
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
