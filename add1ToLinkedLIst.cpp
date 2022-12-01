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
    (*head_ref) = new_node;
}
// TODO: REVERSE THE LINK LIST
Node *reverseList(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

Node *addOne(Node *head)
{
    head = reverseList(head);
    int carry = 1;
    Node *current = head;
    while (carry)
    {
        current->data += 1;
        if (current->data < 10)
        {
            return reverseList(head);
        }
        else
        {
            current->data = 0;
        }
        if (current->next == NULL)
        {
            return 0;
        }
        else
        {
            current = current->next;
        }
    }
}

// TODO: ADD 1 TO THE LINK LIST
// Node *addOne(Node *head)
// {
//     head = reverseList(head);
//     int carry = 1;
//     Node *current = head;
//     while (carry)
//     {
//         current->data += 1;
//         if (current->data < 10)
//         {
//             return reverseList(head);
//         }
//         else
//         {
//             current->data = 0;
//         }
//         if (current->next == NULL)
//         {
//             return 0;
//         }
//         else
//         {
//             current = current->next;
//         }
//     }
// }

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
    // push(&head, 0);
    push(&head, 2);
    printList(head);
    head = reverseList(head);
    cout << endl
         << "reversed list..." << endl;
    printList(head);
    head = addOne(head);
    cout << endl
         << "Result after adding One: " << endl;
    printList(head);
    return 0;
}