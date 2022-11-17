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

Node* add(Node* first, Node* second){
    int carry =0 ;
    while (first!=NULL && second!=NULL)
    {
        int sum = carry + first->data + second->data;
    }
    
}

Node* addList(Node* first, Node* second){
    // step 1: reverse input of linked list
    first = reverse(first);
    second = reverse(second);
    // step 2: add two linked list
    Node* ans = add(first, second);
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
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    printList(head);

    return 0;
}