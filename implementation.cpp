#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// insert an element in the linked list
void push(Node **head_ref, int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
// insert at specific position
void insertAt(Node *prev_node, int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    // base case
    if (prev_node == NULL)
    {
        cout << "this linked list seems to be empty" << endl;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// deleete node from linked list
void deleteNode(Node **head_ref, int key)
{
    Node *temp = *head_ref;
    Node *prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Element you entered is not found..." << endl;
    }

    if (temp != NULL && temp->data != key)
    {
        cout << "Element you entered is not found..." << endl;
    }
    prev->next = temp->next;
    free(temp);
}
// count node in list
int countNode(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void reverseList(Node **head)
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = *head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;

        // update pointers
        prev = current;
        current = next;
    }
    *head = prev;
}

// print linked list
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
    Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    // node will be inserted at the second place but Head node
    insertAt(head, 100);
    printList(head);
    // cout << endl
    //      << "Linked list after deleting the element..." << endl;
    // deleteNode(&head->next, 100);
    // printList(head);
    cout << endl
         << "Total number of elements in the linked list is:" << countNode(head);
    reverseList(&head);
    cout << endl
         << "Linked list after reversing: " << endl;
    printList(head);
    return 0;
}