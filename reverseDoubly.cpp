#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *push(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
}

void reverseList(Node **head_ref)
{
    if ((*head_ref)->next == NULL)
    {
        return;
    }
    Node *temp = NULL;
    Node *current = (*head_ref);

    while (current != NULL)
    {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
    }
    if (temp != NULL)
    {
        (*head_ref) = temp->prev;
    }
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
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
    cout << "\nList after reversing: " << endl;
    reverseList(&head);
    printList(head);
    return 0;
}