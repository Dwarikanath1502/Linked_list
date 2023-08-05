// TODO:    check palindrome in linked list

#include <vector>
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

Node *getMid(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
    }
    return slow;
}

Node *reverse(Node *head)
{
    if (!head)
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
}

bool isPalindrome(Node *head)
{
    //   BASE CASE: if there is only one node then it is palindrome
    if (head->next == NULL)
    {
        return true;
    }
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *temp = slow->next;
    slow->next = reverse(temp);

    Node *head1 = head;
    Node *head2 = temp;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // slow->next = reverse(temp);
    return true;
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
    push(&head, 10);
    push(&head, 10);
    push(&head, 20);
    push(&head, 20);
    push(&head, 10);
    push(&head, 10);
    printList(head);
    if (isPalindrome(head))
    {
        cout << endl
             << "It is palindrome" << endl;
    }
    else
    {
        cout << endl
             << "It is not palindrome" << endl;
    }

    return 0;
}