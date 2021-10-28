//Linked List Cycle
//https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertion(node *&head)
{
    int val;
    cin >> val;
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void traversal(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

//Method: Using Fast & Slow Pointer
//T.C->O(N) & S.C->O(1)
bool hasCycle(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        insertion(head);
    }
    traversal(head);
    bool cycle = hasCycle(head);
    cout<<"Cycle Detected? : "<<cycle<<endl;
    return 0;
}