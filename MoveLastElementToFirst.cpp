// TODO: remove duplicate in sorted linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void moveElement(Node **head_ref)
{

    if ((*head_ref) == NULL || (*head_ref)->next == NULL)
    {
        return;
    }
    Node *secLast = NULL;
    Node *last = (*head_ref);

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = (*head_ref);
    (*head_ref) = last;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    printList(head);
    cout << "\nAfter moving: " << endl;
    moveElement(&head);
    printList(head);
    return 0;
}