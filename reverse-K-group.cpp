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
    // base case
    if (!head)
    {
        return NULL;
    }
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;
    // reverrse k node in linked list
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
        count = count + 1;
    }

    if (next != NULL)
    {
        head->next = Kreverse(next, k);
    }
    // prev is now head of the list
    return prev;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
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
    push(&head, 60);
    print(head);
    cout << "\nReversed linked list: " << endl;
    head = Kreverse(head, 3);
    print(head);
    return 0;
}