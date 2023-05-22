// Add two liniked list

#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
};

void insert(Node** head_ref, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }    
}





int main()
{
    Node *head = NULL;
    insert(&head, 5);
    insert(&head, 4);
    cout<<"List 1: "<<endl;
    printList(head);
    Node* head2 = NULL;
    insert(&head2, 3);
    insert(&head2, 4);
    insert(&head2, 5);
    cout<<endl<<"List 2: "<<endl;
    printList(head2);
    return 0;
}