#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int countLength(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int count = 0;
    while (node != NULL)
    {
        node = node->next;
        count++;
    }
    return count;
}

Node *getIntersection(Node *A, Node *B)
{
    // get the length of both the lists
    int lengthA = countLength(A);
    int lengthB = countLength(B);

    // move the longer node forward and make length of both the lists equal

    // if first node has more elements
    while (lengthA > lengthB)
    {
        A = A->next;
        // reduce the length of A
        lengthA--;
    }

    // if list B has more nodes
    while (lengthB > lengthA)
    {
        B = B->next;
        // reduce length
        lengthB--;
    }
    // NOW BOTH THE LISTS HAVE SAME LENGTH

    while (A != B)
    {
        A = A->next;
        B = B->next;
    }
    return A;
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
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);

    Node *head2 = new Node(10);
    head2->next = new Node(9);
    head2->next->next = new Node(8);
    head2->next->next = head1->next->next->next;

    Node *res = getIntersection(head1, head2);

    if(res){
        cout<<"Intersection is : "<<res->data<<" ";
    }else{
        cout<<"NOT FOUND..."<<endl;
    }
    return 0;
}