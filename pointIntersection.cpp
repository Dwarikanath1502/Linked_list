/*
. Intersection of Two Linked Lists

Given the heads of two singly linked-lists  
headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
// TIME CO<PLEXITY
The overall time complexity of your solution is dominated by the initial counting step and the 
finding intersection step. In the worst case, 
it can be approximated as O(m + n), where m and n are the lengths of List A and List B respectively.

TODO: WORKING ON LEETCODE

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

Node *intersection(Node *headA, Node *headB)
{
    // make the length of both the list samer as we can traverse equally to bothe node
    Node *current = headA;
    int a = 0, b = 0;
    // count length of headA list
    while (current)
    {
        a++;
        current = current->next;
    }
    // count for headB
    current = headB;
    while (current)
    {
        b++;
        current = current->next;
    }
    // find the difference between size of the node
    int diff = abs(a - b);
    // make both the list size equal

    if (a < b)
    {
        while (diff--)
        {
            headB = headB->next;
        }
    }
    else
    {
        while (diff--)
        {
            headA = headA->next;
        }
    }
    // now loop through the node util it becomes null
    while (headA and headB)
    {
        if (headA == headB)
        {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
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
    cout << "LIST A: ";
    printList(first);
    cout << endl
         << "LIST B: ";
    printList(second);
    cout << endl
         << "Intersection: ";

    Node *ans = intersection(first, second);
    printList(ans);
    return 0;
}
