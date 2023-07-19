//Double Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void Push_Doubly(Node **head, int newdata)
{
    Node *newnode = new Node();
    newnode->data = newdata;
    /* As we are inserting value at the beginning,prev is always NULL */
    newnode->prev = NULL;
    /* link new node's next to head */
    newnode->next = (*head);
    /* change prev of head node to newnode */
    if ((*head) != NULL)
        (*head)->prev = newnode;
    /* changing head node */
    (*head) = newnode;
}
void Dispplay_Doubly(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    /* start with an empty list */
    Node *head = NULL;
    Push_Doubly(&head, 9);
    Push_Doubly(&head, 4);
    Push_Doubly(&head, 8);
    cout << "Congratulations: Doubly Linked list is created using classes." << endl;

    Dispplay_Doubly(head);

    return 0;
}