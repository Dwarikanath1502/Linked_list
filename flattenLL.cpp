#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        bottom = NULL;
    }
};

// method to merge two list of the flatten linked list
Node *mergeTwoList(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            temp->bottom = first;
            first = first->bottom;
        }
        else
        {
            temp->bottom = second;
            second = second->bottom;
        }
        temp = temp->bottom;
    }
    if (first != NULL)
    {
        temp->bottom = first;
    }
    if (second != NULL)
    {
        temp->bottom = second;
    }
    return ans->bottom;
}

// method to flatten linked list
Node *flatten(Node *root)
{
    // base case
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    // recursion to right
    root->next = flatten(root->next);

    root = mergeTwoList(root, root->next);

    return root;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data<<" ";
        head = head->bottom;
    }
}

int main()
{
    Node *head = new Node(5);
    auto temp = head;
    auto bt = head;
    bt->bottom = new Node(7);
    bt->bottom->bottom = new Node(8);
    bt->bottom->bottom->bottom = new Node(30);
    temp->next = new Node(10);

    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(20);
    temp->next = new Node(19);
    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(22);
    bt->bottom->bottom = new Node(50);
    temp->next = new Node(28);
    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(35);
    bt->bottom->bottom = new Node(40);
    bt->bottom->bottom->bottom = new Node(45);

    head = flatten(head);
    printList(head);
    return 0;
}