/*
TODO: Given a linked list where every node represents a linked list and contains two pointers of its type:

Pointer to next node in the main list (we call it ‘right’ pointer in the code below)
Pointer to a linked list where this node is headed (we call it the ‘down’ pointer in the code below).
Note: All linked lists are sorted and the resultant linked list should also be sorted

Examples:

Input:    5 -> 10 -> 19 -> 28
               |        |         |        |
              V       V       V       V
              7      20      22     35
               |                 |        |
              V               V       V
              8               50     40
              |                          |
             V                        V
            30                       45


Output: 5->7->8->10->19->20->22->28->30->35->40->45->50

Input:    3 -> 10 -> 7 -> 14
               |        |         |        |
              V       V       V       V
              9      47      15     22
               |                 |
              V                V
              17              30

Output: 3->7->9->10->14->15->17->22->30->47

// APPROACH:
    compare two linked from from last using recusion and merge then and so on until all lists are merged
    TimeComplexity: as we are traversing through all the nodes so summation of all the nodes
    will be time complexity O(summation of all nodes)
    SpaceComplexity: O(1)

    Considering the dominant term, which is O(N), the overall time complexity of the given code is O(N).

The space complexity of the code is O(1), as it only uses a constant amount of extra space for
variables and temporary nodes regardless of the input size.


*/

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

Node *merge(Node *first, Node *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

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
    // if first or second have more element
    if (first != NULL)
    {
        temp->bottom = first;
    }
    else
    {
        temp->bottom = second;
    }
    // becausfirst element of ans is -1
    ans = ans->bottom;
    return ans;
}

Node *flatten(Node *root)
{
    // BASE CASE:
    if (root == NULL || root->next == NULL)
    {
        return root;
    }

    // right recusion to list so that it merges two end list
    root->next = flatten(root->next);

    // merge root and root->next and return merged list to root
    root = merge(root, root->next);
    return root;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
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