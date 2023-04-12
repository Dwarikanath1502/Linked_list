#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/*TODO: It will take time complexity of O(n2)*/

// Node *removeDuplicate(Node *head)
// {
//     Node *current = head;
//     while (current != NULL)
//     {
//         Node *temp = current->next;
//         while (temp != NULL)
//         {
//             if (current->data == temp->data)
//             {
//                 current->next = temp->next;
//                 free(temp);
//                 removeDuplicate(current);
//             }
//             else
//             {
//                 removeDuplicate(current->next);
//             }
//         }
//     }
// }

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