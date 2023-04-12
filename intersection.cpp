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

Node *intersection(Node *head1, Node *head2)
{
    Node *first = head1;
    Node *second = head2;
    while (first != second)
    {
        if (first == NULL)
        {
            first = head2;
        }
        else
        {
            first = first->next;
        }
        if (second = NULL)
        {
            second = head1;
        }
        else
        {
            second = second->next;
        }
    }
    return first;
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
    Node *first = NULL;
    Node *second = NULL;
    push(&first, 1);
    push(&first, 3);
    push(&first, 7);
    push(&first, 9);
    push(&first, 11);
    push(&second, 11);
    push(&second, 19);
    push(&second, 13);
    push(&second, 21);
    push(&second, 7);
    Node *ans = NULL;
    ans = intersection(first, second);
    printList(ans);
    return 0;
}