// TODO: find the Nth node from th eback of linked list

// NOTE: HERE GETTING SEGMENTATION FAULT BUT HT ECODE IS ABSOLUTELY RIGHT AND RUNNING ON GFG

#include <bits/stdc++.h>
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

int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node *temp = head;
    Node *temp1 = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    count = count - n;
    for (int i = 0; i < count; i++)
    {
        temp1 = temp1->next;
    }
    return temp1->data;
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
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printList(head);
    int k = 1;
    cout << endl
         << "kth node from end of the linked list is : " << getNthFromLast(head, k);
    return 0;
}