// Given a singly linked list, remove all the nodes which have a greater value on the right side.

// Examples:
// a) The list 12->15->10->11->5->6->2->3->NULL should be changed to 15->11->6->3->NULL. Note that 12, 10, 5 and 2 have been deleted because there is a greater value on the right side.
// When we examine 12, we see that after 12 there is one node with a value greater than 12 (i.e. 15), so we delete 12.
// When we examine 15, we find no node after 15 that has a value greater than 15, so we keep this node.
// When we go like this, we get 15->11->6->3->NULL
// b) The list 10->20->30->40->50->60->NULL should be changed to 60->NULL. Note that 10, 20, 30, 40, and 50 have been deleted because they all have a greater value on the right side.
// c) The list 60->50->40->30->20->10->NULL should not be changed.

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

Node *reverse(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;

        // update popinter
        prev = current;
        current = next;
    }
    return prev;
}

Node *deleteLeftHavingLargerOnRight(Node *head)
{
    head = reverse(head);
    int maxElement = head->data;
    Node *current = head;
    Node *prev = head;
    head = head->next;
    while (head != NULL)
    {
        if (head->data >= maxElement)
        {
            maxElement = head->data;
            prev = head;
            head = head->next; // prev->next
        }
        else
        {
            prev->next = head->next;
            head = prev->next;
        }
    }
    head = reverse(current);
    return head;
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

    /* Create following linked list
    12->15->10->11->5->6->2->3 */
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 12);

    cout << "Given Linked List \n"
         << endl;
    printList(head);

    Node *ans = deleteLeftHavingLargerOnRight(head);

    cout << endl
         << "Modified Linked List \n";
    printList(ans);
    return 0;
}
