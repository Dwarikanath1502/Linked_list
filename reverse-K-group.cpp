// TODO: REVERSE LINKED LIST IN K GROUP

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

Node *reverse(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;
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
        head->next = reverse(next, k);
    }
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
    head = reverse(head, 3);
    print(head);
    return 0;
}