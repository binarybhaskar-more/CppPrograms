#include <iostream>
using namespace std;

class node {
    int data;
    node *next = nullptr;
public:
    node(int d) : data(d) {};
    node(int d, node* n) : data(d), next(n) {};

    friend void insertAtBeginning(node*& head, int d) { head = new node(d, head); }

    friend void insertAtEnd(node*& head, int d) {
        if (head == nullptr) insertAtBeginning(head, d);
        node* t = head;
        while (t->next != nullptr) t = t->next;
        t->next = new node(d);
    }

    void operator+ (node*& otherHead) {
    }

    friend void insertAtPos(node*& head, int d, int pos) {
        if (head == nullptr) {
            cout << "Invalid position\n";
        }

        node* t = head;
        node* prev = nullptr;
        int currPos = 1;

        while (t->next != nullptr && currPos++ < pos) {
            prev = t;
            t = t->next;
            if (currPos == pos) {
                prev->next = new node(d, t);
                return;
            } else if (t->next == nullptr) {
                cout << "Invalid position\n";
                return;
            }
        }
        return;
    }

    friend std::ostream& operator<<(std::ostream& out, node* head) {
        node* t = head;
        if (t == nullptr) {
            out << "Empty Singly Linked List";
            return out;
        }

        while (t != nullptr) {
            out << t->data;
            t = t->next;
            if (t != nullptr) out << " -> ";
        }
        return out;
    } 
};

int main() {
    node* head = nullptr;
    insertAtBeginning(head, -1);
    insertAtBeginning(head, -2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtPos(head, 0, 3);
    cout << head << endl;
    return 0;
}