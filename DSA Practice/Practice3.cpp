#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack
{
private:
    int arr[MAX_SIZE];
    int top; // Index of the top element in the stack

public:
    Stack()
    {
        top = -1; // Initialize the stack with an invalid index
    }

    bool isEmpty()
    {
        return (top == -1); // If the top is -1, the stack is empty
    }

    bool isFull()
    {
        return (top == MAX_SIZE - 1); // If the top is at the maximum index, the stack is full
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack overflow: Cannot push element, stack is full." << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow: Cannot pop element, stack is empty." << endl;
            return;
        }

        top--;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, cannot peek." << endl;
            return -1;
        }

        return arr[top];
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();

    cout << "Top element after popping: " << stack.peek() << endl;

    return 0;
}