// TODO: FIND MIDDLE OF THE LINKED LIST
// SOLVING USING TWO APPROACH
// APPROACH : 1

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
// };

// void push(Node **head_ref, int data)
// {
//     Node *new_node = new Node();
//     new_node->data = data;
//     new_node->next = (*head_ref);
//     (*head_ref) = new_node;
// }

// void printMiddle(Node *head)
// {
//     if (head == NULL)
//     {
//         return;
//     }
//     Node *slow = head;
//     Node *fast = head;
//     while (fast->next != NULL && fast != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next;
//         if (fast != NULL)
//         {
//             fast = fast->next;
//         }
//     }
//     cout << "\nMiddle of the element is :" << slow->data << endl;
// }

// void printList(Node *head)
// {
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->next;
//     }
// }

// int main()
// {
//     Node *head = NULL;
//     push(&head, 10);
//     push(&head, 20);
//     push(&head, 30);
//     // push(&head, 30);
//     // push(&head, 30);
//     // push(&head, 40);
//     printList(head);
//     printMiddle(head);
//     return 0;
// }

// APPROACH : 2

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

int countElement(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

int middleElement(Node *head)
{
    int total = countElement(head);
    int midIndex = total / 2;
    Node *temp = head;
    while (midIndex--)
    {
        temp = temp->next;
    }
    cout << "\nMiddle of the element is: " << temp->data << endl;
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
    Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    printList(head);
    cout << "\nTotal element is : " << countElement(head);
    middleElement(head);
    return 0;
}