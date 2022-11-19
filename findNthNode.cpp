

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

int length(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int NthNode(Node *head, int n)
{
    Node *temp = head;
    int count = length(head);
    if (count < n)
    {
        return -1;
    }
    // TODO:   BOTHAPPRACHES ARE CORRECT
    // count = count - n;
    // for (int i = 0; i < count; i++)
    // {
    //     temp = temp->next;
    // }
    // return temp->data;
    count = count - n + 1;
    for (int i = 1; i < count; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    printList(head);
    cout << endl
         << "- - - - - - - - - - - -" << endl;
    cout << "Element is: " << NthNode(head, 2);
    return 0;
}