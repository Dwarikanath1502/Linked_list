        // TODO: REVERSE THE LINKED LIST

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

Node* reverseList(Node *head)
{
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    while (current!= NULL)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;
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
    print(head);
    cout<<"\nReversed linked list: "<<endl;
    head = reverseList(head);
    print(head);
    return 0;
}