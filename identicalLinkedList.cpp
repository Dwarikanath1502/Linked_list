// TODO: ch3eck wheather two lists are idfentical

/*
Two Linked Lists are identical when they have the same data and the arrangement of data is also the same. Write a function to check if the given two linked lists are identical.

Examples:

Input: a = 1->2->3->4,
       b = 1->2->3->4
Output: Identical

Input: a = 1->3->5->2,
       b = 1->3->4->6
Output: Not Identical
*/

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

// method to check wheather lists are identical or not
bool isIdentical(Node *head1, Node *head2)
{
    // BASE CASE: if both is null
    if ((head1 == NULL) && (head2 == NULL))
    {
        return true;
    }

    // loop through both the list and find wather they are same
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // return true;

    return (head1 == NULL && head2 == NULL);
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head2, 1);
    push(&head2, 2);
    push(&head2, 3);
    cout << "Elements of first list is : ";
    printList(head1);
    cout << endl
         << "Elements of second list is : ";
    printList(head2);
    if (isIdentical(head1, head2))
    {
        cout << endl
             << "Both the lists are Identical...";
    }
    else
    {
        cout << endl
             << "Lists are not identical...";
    }

    return 0;
}