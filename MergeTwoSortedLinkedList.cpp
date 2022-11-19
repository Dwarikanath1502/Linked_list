// TODO: merge two sorted llinked list

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

Node* mergeList(Node* first , Node* second){
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first ;   
    }
    
    
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

    return 0;
}