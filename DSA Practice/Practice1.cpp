#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Default Constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int val) {
    Node *n = new Node(val);

    if (head == NULL) {
        head = n;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(Node *head, int val) {
    Node *temp = head;

    while (temp != NULL) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

int main() {
    Node *head = NULL;
    insertAtTail(head, 1);
    display(head);
    insertAtTail(head, 2);
    display(head);

    // Search for a value
    int searchValue = 2;
    if (search(head, searchValue)) {
        cout << searchValue << " is found in the linked list." << endl;
    } else {
        cout << searchValue << " is not found in the linked list." << endl;
    }

    return 0;
}