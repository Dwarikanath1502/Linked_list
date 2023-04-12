// TODO: Split a Circular Linked List into two halves
#include <iostream>
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

void splitList(Node *head, Node **head_ref1, Node **head_ref2)
{

    // assign
    Node *slow = head;
    Node *fast = head->next;
    while (fast != head && (fast->next) != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head_ref1 = head;
    *head_ref2 = slow->next;
    slow->next = (*head_ref1);
    Node *current = (*head_ref2);
    while (current->next != head)
    {
        current = current->next;
    }
    current->next = (*head_ref2);
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Node *head_ref1 = NULL;
    Node *head_ref2 = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    printList(head);
    splitList(head, &head_ref1, &head_ref2);
    cout << "First linked list: " << endl;
    printList(head_ref1);
    cout << "second linked list: " << endl;
    printList(head_ref2);
    return 0;
}
