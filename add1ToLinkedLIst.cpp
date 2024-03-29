// TODO: Add 1 to linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *insert(int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *reverseList(Node *head)
{

    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

Node *addOne(Node *head)
{
    head = reverseList(head);
    int carry = 1;
    Node *current = head;
    while (current)
    {
        int value = current->data + carry;
        carry = (value / 10);
        current->data = value % 10;
        current = current->next;
    }
    if (carry)
    {
        Node *new_node = new Node();
        new_node->data = carry;
        new_node->next = head;
        head = new_node;
    }
    return reverseList(head);
}

// Node *addUtil(Node *head)
// {
//     Node *result = head;
//     Node *temp, *prev = NULL;
//     int carry = 1, sum;

//     while (head != NULL)
//     {
//         sum = carry + (head ? head->data : 0);
//         carry = sum > 10 ? 1 : 0;
//         sum = sum % 10;
//         head->data = sum;
//         temp = head;
//         head = head->next;
//     }
//     if (carry > 0)
//     {
//         temp->next = insert(&head, carry);
//     }
//     return result;
// }

int main(int argc, char const *argv[])
{
    Node *head = insert(1);
    head->next = insert(9);
    head->next->next = insert(9);
    head->next->next->next = insert(9);

    cout << "List is ";
    printList(head);

    head = addOne(head);

    cout << "\nResultant list is ";
    printList(head);

    return 0;
}
