// TODO: WAP TO REVERSE THE LINKED LIST

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// method to push element to the list
void push(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// reverse the list
Node *reverseList(Node *head)
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;

        // update pointer
        prev = current;
        current = next;
    }
    return prev;
}

// print list
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
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    cout<<"List before reversing: ";
    printList(head);
    head = reverseList(head);
    cout<<endl<<"List after reversing: ";
    printList(head);
    return 0;
}
