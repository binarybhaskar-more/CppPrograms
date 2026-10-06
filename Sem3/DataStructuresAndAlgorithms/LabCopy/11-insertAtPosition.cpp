#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtPosition(Node*& head, int val, int pos) {
    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }
    if (pos == 1) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Invalid position!\n";
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
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
    int n, pos, val;

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

    cout << "Enter the position to insert the new element: ";
    cin >> pos;
    cout << "Enter the value: ";
    cin >> val;

    insertAtPosition(head, val, pos);

    cout << "Linked list after insertion: ";
    display(head);

    return 0;
}
