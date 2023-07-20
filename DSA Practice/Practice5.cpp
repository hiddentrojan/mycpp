#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack
{
private:
    char arr[MAX_SIZE];
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

    void push(char value)
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

    char peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, cannot peek." << endl;
            return '\0';
        }

        return arr[top];
    }
};

bool isBalancedParentheses(const string &str)
{
    Stack parenStack;

    for (char ch : str)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            parenStack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (parenStack.isEmpty())
            {
                return false;
            }

            char top = parenStack.peek();

            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
            {
                parenStack.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return parenStack.isEmpty();
}

int main()
{
    string str1 = "([]){}"; // Balanced
    string str2 = "({[)]";  // Not balanced

    cout << "String 1 is " << (isBalancedParentheses(str1) ? "balanced" : "not balanced") << endl;
    cout << "String 2 is " << (isBalancedParentheses(str2) ? "balanced" : "not balanced") << endl;

    return 0;
}
