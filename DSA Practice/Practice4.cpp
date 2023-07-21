#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr; // Initialize the stack with an empty linked list
    }

    bool isEmpty() {
        return (top == nullptr); // If top is null, the stack is empty
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow: Cannot pop element, stack is empty." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot peek." << endl;
            return -1;
        }

        return top->data;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();

    cout << "Top element after popping: " << stack.peek() << endl;

    return 0;
}
