/*
TODO: remove duplicates from unsorted likedlist

TC: O(N)
SC:O(N)

APPROACH:
    if no element in the list return NULL, else push the first element in an unordered_set
    loop throught the list while current && current->next is not null and compare whather current->next->data
    is present in the list or not
    * if present -> make current->next = current->next->next
    * if not present push current->next->data to the list and move current = current->next;


*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// method to remove duplicates from unsortedlinked list

Node *removeDuplicate(Node *head)
{
    unordered_set<int> seen;
    Node *current = head;

    if (current == NULL)
    {
        return head;
    }
    else
    {
        seen.insert(current->data);
    }

    while (current != NULL && current->next != NULL)
    {
        // same
        if (seen.find(current->next->data) != seen.end())
        {
            current->next = current->next->next;
        }
        else
        {
            // not same
            seen.insert(current->next->data);
            current = current->next;
        }
    }
    return head;
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
    push(&head, 5);
    push(&head, 15);
    push(&head, 5);
    push(&head, 15);
    push(&head, 12);
    push(&head, 13);
    push(&head, 14);
    push(&head, 1);
    cout << "List before removal of duplicates: ";
    printList(head);
    cout << endl
         << "List after removal of duplicates: ";
    head = removeDuplicate(head);
    printList(head);
    return 0;
}