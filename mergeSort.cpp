// TODO: merge two sorted llinked list

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
        next = NULL;
    }
};

Node* findMid(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge(Node *first, Node *second)
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
            temp->next = first;
            // temp = first;
            first = first->next;
        }
        else
        {
            temp->next = second;
            // temp = second;
            second = second->next;
        }
        temp = temp->next;
    }
    if (first!=NULL)
    {
        temp->next = first;
    }
    if (second!=NULL)
    {
        temp->next = second;
        
    }
    
    
    ans = ans->next;
    return ans;
}

Node *mergeSort(Node *head)
{
    //    base casew
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    Node *result = merge(left, right);
    return result;
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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(90);
    head->next->next->next->next->next = new Node(9);
    cout << "List before Merge sort: " << endl;
    printList(head);
    head = mergeSort(head);
    cout<<"List after merge sort"<<endl;
    printList(head);
    return 0;
}