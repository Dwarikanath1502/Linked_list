                // FIXME:
                // ?TODO: DO IT.

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

Node *removeDupicate(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        // Node* temp = current->next;
        while (current->next != NULL)
        {
            if (current->data == current->next->data)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                free(temp);
            }
            else
            {
                current->next = current->next->next;
            }
            current = current->next;
        }
    }
}

void print(Node *head)
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
    push(&head, 10);
    push(&head, 40);
    push(&head, 30);
    push(&head, 30);
    push(&head, 10);
    push(&head, 20);
    print(head);
    cout << "\nAfter Removing: " << endl;
    removeDupicate(head);
    return 0;
}