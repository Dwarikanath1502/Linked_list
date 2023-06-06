// TODO: find the intersection of two inked list

/*
APPROACH
    push all the elements of head1 to set, then find all the elements of head2 in set till end
    if it matches then store the head2->data to result vector and increment count od index and
     head = head->next

     when head2 gets null return ans

*/

#include <bits/stdc++.h>
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

vector<int> intersection(Node *head1, Node *head2, int k)
{
    vector<int> res(k);
    unordered_set<int> set;

    while (head1 != NULL)
    {
        set.insert(head1->data);
        head1 = head1->next;
    }

    // to keep track of element in res array
    int count = 0;
    while (head2 != NULL)
    {
        if (set.find(head2->data) != set.end())
        {
            res[count] = head2->data;
            count++;
        }
        head2 = head2->next;
    }
    return res;
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
    Node *first = NULL;
    Node *second = NULL;
    push(&first, 1);
    push(&first, 3);
    push(&first, 7);
    push(&first, 9);
    push(&first, 11);
    push(&second, 11);
    push(&second, 19);
    push(&second, 13);
    push(&second, 21);
    push(&second, 7);
    Node *ans = NULL;
    vector<int> arr = intersection(first, second, 2);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}