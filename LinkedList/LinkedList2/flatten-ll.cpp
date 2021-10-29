//Flattening a Linked List
//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *bottom;
    node(int val)
    {
        data = val;
        next = NULL;
        bottom = NULL;
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

//Method: Using Recursion & Merge Sort
//T.C->O(N*M) & S.C->O(1), Auxilary Space->O(N)

node *merge(node *a, node *b)
{
    node *temp = new node(0);
    node *res = temp;
    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if (a != NULL)
    {
        temp->bottom = a;
    }
    else
    {
        temp->bottom = b;
    }
    return res->bottom;
}

node *flatten(node *root)
{
    // Your code here
    if (root == NULL || root->next == NULL)
    {
        return root;
    }

    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
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
    return 0;
}