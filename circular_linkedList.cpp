// TODO:    CIRCULAR LINKED LIST and check is it circular

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
    Node *temp = (*head_ref);
    if ((*head_ref) != NULL)
    {
        while (temp->next != (*head_ref))
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else
    {
        new_node->next = new_node;
    }

    (*head_ref) = new_node;
}

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    Node *temp = head;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return 0;
    }
    if (temp == head)
    {
        return 1;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    do
    {
        cout << head->data << " ";
        head = head->next;
    } while (temp != head);
}

int main()
{
    Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    printList(head);
    if (isCircular(head))
    {
        cout << "\nit is circular" << endl;
    }
    else
    {
        cout << "\nNot circular" << endl;
    }
    return 0;
}