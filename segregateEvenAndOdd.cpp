// TODO: , write a function to modify the linked list such that all even numbers appear before all the 
// odd numbers in the modified linked list. Also, keep the order of even and odd numbers the same.

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

void segregate(Node **head_ref)
{
    Node *evenStart = NULL;
    Node *evenEnd = NULL;
    Node *oddStart = NULL;
    Node *oddEnd = NULL;
    Node *current = (*head_ref);

    while (current != NULL)
    {
        int val = current->data;
        if (val % 2 == 0)
        {
            if (evenStart == NULL)
            {
                evenStart = current;
                evenEnd = evenStart;
            }
            else
            {
                evenEnd->next = current;
                evenEnd = evenEnd->next;
            }
        }
        else
        {
            if (oddStart == NULL)
            {
                oddStart = current;
                oddEnd = oddStart;
            }
            else
            {
                oddEnd->next = current;
                oddEnd = oddEnd->next;
            }
        }

        current = current->next;
    }
    if (oddStart == NULL || evenStart == NULL)
    {
        return;
    }
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    (*head_ref) = evenStart;
}

int main()
{
    Node *head = NULL;

    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 13);
    push(&head, 19);
    push(&head, 4);
    push(&head, 1);
    push(&head, 0);
    cout << "original Linked list:" << endl;
    printList(head);
    segregate(&head);
    cout << endl
         << "List after arranging" << endl;
    printList(head);
    return 0;
}