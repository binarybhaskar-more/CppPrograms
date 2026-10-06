#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "Empty Linked List\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n, val;

    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    if (n > 0) {
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    cout << "Linked list before insertion: ";
    display(head);

    cout << "Enter the value to insert at end: ";
    cin >> val;

    insertAtEnd(head, val);

    cout << "Linked list after insertion: ";
    display(head);

    return 0;
}
