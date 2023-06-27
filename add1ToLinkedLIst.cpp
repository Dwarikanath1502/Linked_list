// TODO: Add 1 to linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *insert(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
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

Node *addUtil(Node *head)
{
    Node *result = head;
    Node *temp, *prev = NULL;
    int carry = 1, sum;

    while (head != NULL)
    {
        sum = carry + (head ? head->data : 0);
        carry = sum > 10 ? 1 : 0;
        sum = sum % 10;
        head->data = sum;
        temp = head;
        head = head->next;
    }
    if (carry > 0)
    {
        temp->next = insert(&head, carry);
    }
    return result;
}

Node *addOne(Node *head)
{
    // reverse linked list
    head = reverseList(head);

    head = addUtil(head);

    return reverseList(head);
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    insert(&head, 5);
    insert(&head, 4);

    head = addOne(head);
    printList(head);
    return 0;
}
