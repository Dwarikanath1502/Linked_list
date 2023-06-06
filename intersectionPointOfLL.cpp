/*
TODO: Intersection Point of Two Linked Lists

Use 2 nested for loops.
The outer loop will be for each node of the 1st list and the inner loop will be for the 2nd list.
In the inner loop, check if any of the nodes of the 2nd list is the same as the current node of the
 first linked list.
  The TIME COMPLEXITY of this method will be O(M * N) where m and n are the numbers
 of nodes in two lists.
*/

#include <iostream>
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

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *getIntersection(Node *head1, Node *head2)
{
    while (head1 != NULL)
    {
        Node *temp = head2;
        while (temp)
        {
            if (temp == head1)
            {
                return temp;
            }
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return NULL;
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
    if (!res)
    {
        cout << "NO intersection point" << endl;
    }
    else
    {
        cout << "Intersection point is: " << res->data << endl;
    }
}