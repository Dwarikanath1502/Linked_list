// TODO: ADD TEO NUMBERS REPRESENTED BY LINKED LIST
// FIXME:
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

Node *reverse(Node *head)
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

Node *add(Node *first, Node *second)
{
    int carry = 0;
    while (first != NULL && second != NULL)
    {
        int sum = carry + first->data + second->data;
    }
}

Node *addList(Node *first, Node *second)
{
    // step 1: reverse input of linked list
    first = reverse(first);
    second = reverse(second);
    // step 2: add two linked list
    Node *ans = add(first, second);
    // step 3: reverse ans to get final ans
    ans = reverse(ans);
    return ans;
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
    Node *head1 = NULL;
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    cout << "Node 1: " << endl;
    printList(head1);

    Node *head2 = NULL;
    push(&head2, 1);
    push(&head2, 2);
    push(&head2, 3);
    cout << endl
         << "Node 2: " << endl;
    printList(head2);
    cout <<endl<< "SUM: " << endl;
    Node *sum = NULL;
    sum = addList(head1, head2);
    printList(sum);
    return 0;
}