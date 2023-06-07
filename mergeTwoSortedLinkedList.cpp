// TODO: merge two sorted linked list here creating problem 
/*
    CODE WORKING FINE ON GFG PRATICE    
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

// this function is merging two list
Node *solve(Node *first, Node *second)
{
    // if only one element isNode present in first list
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }
    Node *current1 = first;
    Node *next1 = current1->next;

    Node *current2 = second;
    Node *next2 = current2->next;

    while (next1 != NULL && current2 != NULL)
    {
        if ((current2->data >= current1->data) && (current2->data <= next1->data))
        {
            // add node in between first node
            current1->next = current2;
            next2 = current2->next;
            current2->next = next1;
            // update pointer
            current1 = current2;
            current2 = next2;
        }
        else
        {
            // current1 and next1 move by 1
            current1 = next1;
            next1 = next1->next;

            // check if next1!=NULL
            if (next1 == NULL)
            {
                current1->next = current2;
                return first;
            }
        }
    }
    return first;
}

Node *mergeTwoList(Node *first, Node *second)
{

    if (first == NULL)
    {
        return second;
    } 
    if (second == NULL)
    {
        return first;
    }
    // check wheter whose first element is smaller ans assume first whose val is smaller
    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    // head1 elements
    push(&head1, 1);
    push(&head1, 4);
    push(&head1, 5);
    // printList(head1);
    // head2 elements
    push(&head2, 2);
    push(&head2, 3);
    push(&head2, 5);
    // merge Function
    Node *result = mergeTwoList(head1, head2);
    cout << "Merge linked list: ";
    printList(result);
    return 0;
}