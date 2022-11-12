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
// TODO: find loop
Node *findLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        if (slow == fast)
        {
            // cout<<"Loop is present at: "<<slow->data;
            return slow;
        }
    }
    return NULL;
}
// TODO: find starting node of loop
Node *findStart(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *intersection = findLoop(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
// TODO: remove loop
Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *startOfLoop = findStart(head);
    Node *temp = startOfLoop;
    while (temp != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    print(head);
    head->next->next->next = head->next;
    if (findLoop(head) != NULL)
    {
        cout << "\nCycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }
    cout << "cycle starting at: " << findStart(head)->data << endl;
    removeLoop(head);
    if (findLoop(head) != NULL)
    {
        cout << "\nLoop is present" << endl;
    }
    else
    {
        cout << "Loop is not present" << endl;
    }
    return 0;
}