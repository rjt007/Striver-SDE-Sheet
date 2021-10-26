//Delete Node in a Linked List
//https://leetcode.com/problems/delete-node-in-a-linked-list/
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

/* //Method1: Brute Force
//T.C->O(N) & S.C->O(1)
void deleteNode(node *temp)
{
    while (temp->next->next != NULL)
    {
        int swap = temp->data;
        temp->data = temp->next->data;
        temp->next->data = swap;

        temp = temp->next;
    }
    temp->data = temp->next->data;
    temp->next = NULL;
} */

//Method2: Highly Optimized
//T.C->O(1) && S.C->O(1)
void deleteNode(node *temp)
{
/*     node *p = temp->next;
    *temp = *p;
    delete p; */
    temp->data = temp->next->data;
    temp->next = temp->next->next;
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
    node* temp = head->next->next;
    deleteNode(temp);
    traversal(head);
    return 0;
}