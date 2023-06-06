// TODO: to check whether two linked list are identical or not
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
};

void push(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

bool isIdentical(Node *list1, Node *list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return true;
    }
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data != list2->data)
        {
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    // return true;
    return (list1 == NULL && list2 == NULL);
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;
    push(&list1, 1);
    push(&list1, 2);
    push(&list1, 3);
    push(&list2, 1);
    push(&list2, 2);
    push(&list2, 3);
    printlist(list1);
    printlist(list2);
    if (isIdentical(list1, list2))
    {
        cout << endl
             << "Both the lists are Identical...";
    }
    else
    {
        cout << "Not identical..." << endl;
    }

    return 0;
}