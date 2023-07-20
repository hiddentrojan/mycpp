#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE];
    int top; // Index of the top element in the stack

public:
    Stack() {
        top = -1; // Initialize the stack with an invalid index
    }

    bool isEmpty() {
        return (top == -1); // If the top is -1, the stack is empty
    }

    bool isFull() {
        return (top == MAX_SIZE - 1); // If the top is at the maximum index, the stack is full
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow: Cannot push element, stack is full." << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow: Cannot pop element, stack is empty." << endl;
            return;
        }

        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot peek." << endl;
            return -1;
        }

        return arr[top];
    }
};

bool isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

int evaluatePostfixExpression(const string& postfix) {
    Stack s;

    for (char ch : postfix) {
        if (isOperand(ch)) {
            s.push(ch - '0'); // Convert the character digit to its integer value and push it into the stack
        } else {
            int operand2 = s.peek();
            s.pop();
            int operand1 = s.peek();
            s.pop();

            int result;
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    cout << "Invalid operator." << endl;
                    return 0;
            }

            s.push(result);
        }
    }

    return s.peek();
}

int main() {
    string postfix = "82+3*";

    int result = evaluatePostfixExpression(postfix);
    cout << "Result: " << result << endl;

    return 0;
}