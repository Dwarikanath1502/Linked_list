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
    Node *temp = (*head_ref);
    if ((*head_ref) != NULL)
    {
        while (temp->next != (*head_ref))
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else
    {
        new_node->next = new_node;
    }

    (*head_ref) = new_node;
}

void deleteNode(Node **head_ref, int key)
{
    // CASE 1: IF LINKED LIST IS EMPTY
    if ((*head_ref) == NULL)
    {
        return;
    }

    // CASE 2: ONLY ONE LEMENT
    if ((*head_ref)->data == key && (*head_ref)->next == (*head_ref))
    {
        free(*head_ref);
        (*head_ref) == NULL;
        return;
    }
    Node *temp = (*head_ref);

    // CASE 3: HEAD WITH MANY ELEMENT
    if ((*head_ref)->data == key)
    {
        while (temp->next != (*head_ref))
        {
            temp = temp->next;
        }
        temp->next = (*head_ref)->next;
        free(*head_ref);
        (*head_ref) = temp->next;
    }

    // CASE 4: REGULAR DELETE
    while (temp->next != (*head_ref) && temp->next->data != key)
    {
        temp = temp->next;
    }
    if (temp->next->data == key)
    {
        Node *deleteVal;
        deleteVal = temp->next;
        temp->next = temp->next->next;
        free(deleteVal);
    }

    // CASE 5: NODE NOT FOUND
    else
    {
        cout << "\n Value not found..." << endl;
    }
}

void printList(Node *node)
{
    Node *temp;
    do
    {
        cout << node->data << " ";
        node = node->next;
    } while (temp != node);
}

int main()
{
    Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    printList(head);
    deleteNode(&head, 20);
    cout<<"\nList after deletion..."<<endl;
    printList(head);
    return 0;
}