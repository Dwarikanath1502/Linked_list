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
// TODO: removes duplicate
Node *removeDuplicate(Node *head)
{
    Node *temp;
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next != NULL)
    {
        if (head->data == head->next->data)
        {
            temp = head->next;
            head->next = head->next->next;
            free(temp);
            removeDuplicate(head);
        }
        else
        {
            removeDuplicate(head->next);
        }
    }
}

void printList(Node *head)
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
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 30);
    push(&head, 40);
    printList(head);
    cout<<"\nAfter removing duplicates: "<<endl;
    removeDuplicate(head);
    printList(head);
    return 0;
}