#include <iostream>

using namespace std;

class Stack {
    int size;
    int top;
    int* arr;
public:
    Stack(int s) : size(s), top(-1) {
        arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    void push(int val) {
        if(top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if(top == -1) {
            cout << "Stack Underflow\n";
            return -1; // Indicating stack is empty
        }
        return arr[top--];
    }

    int peek() {
        if(top == -1) {
            cout << "Stack is empty\n";
            return -1; // Indicating stack is empty
        }
        return arr[top];
    }
};

int main() {
    Stack s(3);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.peek() << "\n";
    cout << "Popped element is: " << s.pop() << "\n";
    cout << "Top element after pop is: " << s.peek() << "\n";
    for (int i = 0; i<2; i++) s.push(0);
    for (int i = 0; i<4; i++) s.pop();
    return 0;
}