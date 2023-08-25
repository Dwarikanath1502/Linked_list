// TODO: Delete N-th node from end of the linked list
// BELOW IS O(2N) which is also perfect
//but here alll in O(N) self


// TODO: Delete N-th node from end of the linked list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *insert(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

Node *removeNthFromEnd(Node *head, int n)
{
    Node* dummy = new Node();
    dummy->next = head;
    Node* fast = dummy;
    Node* slow = dummy;
    
    for (int i = 1 ; i <= n; i++)
    {
        fast = fast->next;
    }

    while (fast->next!= NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete(toDelete);
    return dummy->next;
    
    

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
    Node *head = NULL;
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    printList(head);
    int n = 5;
    Node *updated = removeNthFromEnd(head, n);
    cout << endl
         << "List after removing N-th node:";
    printList(updated);
    return 0;
}





// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
// };

// Node *insert(Node **head_ref, int data)
// {
//     Node *new_node = new Node();
//     new_node->data = data;
//     new_node->next = (*head_ref);
//     (*head_ref) = new_node;
// }

// int countNode(Node *head)
// {
//     int count = 0;
//     if (head == NULL)
//     {
//         return 0;
//     }
//     while (head != NULL)
//     {
//         count++;
//         head = head->next;
//     }
//     return count;
// }

// Node *removeNthFromEnd(Node *head, int n)
// {
//     // temporary node to traverse
//     Node *temp = head;
//     if (head == NULL)
//     {
//         return NULL;
//     }
//     int countNodes = countNode(head);

//     if (n > countNodes)
//     {
//         cout << "Invalid Inoput for N";
//         return head;
//     }
//     int toRemove = countNodes - n;

//     // if head node to be deleted
//     if (n == countNodes)
//     {
//         Node *temp = head;
//         head = head->next;
//         delete (temp);
//         return head;
//     }

//     for (int i = 1; i < toRemove; i++)
//     {
//         temp = temp->next;
//     }

//     // hold the temp
//     Node *node = temp->next;
//     temp->next = temp->next->next;
//     delete (node);

//     return head;
// }

// void printList(Node *node)
// {
//     while (node != NULL)
//     {
//         cout << node->data << " ";
//         node = node->next;
//     }
// }

// int main()
// {
//     Node *head = NULL;
//     insert(&head, 5);
//     insert(&head, 4);
//     insert(&head, 3);
//     insert(&head, 2);
//     insert(&head, 1);
//     printList(head);
//     int n = 5;
//     Node *updated = removeNthFromEnd(head, n);
//     cout << endl
//          << "List after removing N-th node:";
//     printList(updated);
//     return 0;
// }