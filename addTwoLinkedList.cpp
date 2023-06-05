// Add two liniked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// void insert(Node **head_ref, int data)
// {
//     Node *new_node = new Node();
//     new_node->data = data;
//     new_node->next = (*head_ref);
//     (*head_ref) = new_node;
// }

Node *reverse(Node *head)
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

Node *addList(Node *first, Node *second)
{
    // step 1:
    first = reverse(first);
    second = reverse(second);
    // step 2:
    int sum = 0;
    int carry = 0;
    Node *temp;
    Node *result = NULL;
    Node *current = NULL;
    // iterate to list
    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = (sum % 10);
        temp = new Node(sum);
        if (result == NULL)
        {
            result = temp;
        }
        else
        {
            current->next = temp;
        }
        current = temp;
        // if element remains
        if (first)
        {
            first = first->next;
        }
        if (second)
        {
            second = second->next;
        }
    }
    // if there is a carry remain
    if (carry > 0)
    {
        temp = new Node(carry);
        current->next = temp;
        current = temp;
    }
    result = reverse(result);
    return result;
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
    insert(&head, 5);
    insert(&head, 4);

    head = reverse(head);

    Node *head2 = NULL;
    insert(&head2, 3);
    insert(&head2, 4);
    insert(&head2, 5);
    head2 = reverse(head2);
    Node *ans = addList(head, head2);
    printList(ans);
    return 0;
}