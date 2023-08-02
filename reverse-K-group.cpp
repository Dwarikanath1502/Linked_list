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

Node *Kreverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    // initialise values
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = head;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;

        // update pointer
        prev = current;
        current = next;
        count = count + 1;
    }
    //    check if next is not null
    if (next != NULL)
    {
        head->next = Kreverse(next, k);
    }
    return prev;
}

void print(Node *head)
{
    Node* current = head;
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
    push(&head, 50);
    cout<<"List before reversal in k Group: ";
    print(head);
    cout << "\nReversed linked list: " << endl;
    head = Kreverse(head, 3);
    print(head);
    return 0;
}