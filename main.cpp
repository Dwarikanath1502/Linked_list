
                // TODO:    create linked list and count number of node

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

int count(Node* head){
    int count = 0;
    while (head!=NULL)
    {
        head = head->next;
        count++;
    }
    return count;
    
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
    Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    print(head);
    cout<<"\nTotal numbers of elements in the list: "<<count(head)<<endl;
    return 0;

}