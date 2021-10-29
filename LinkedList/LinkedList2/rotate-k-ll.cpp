//Rotate List
//https://leetcode.com/problems/rotate-list/
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
//Method: Using Two Pointers
//T.C->O(N) & S.C->O(1)
node *rotateRight(node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    int l = 1;
    node *p1 = head;
    while (p1->next != NULL)
    {
        l++;
        p1 = p1->next;
    }
    //cout<<p1->val<<" ";
    if (k >= l)
    {
        k = k % l;
    }
    int l1 = l - k - 1;
    node *p2 = head;
    while (l1-- && p2->next != NULL)
    {
        p2 = p2->next;
    }
    p1->next = head;
    head = p2->next;
    p2->next = NULL;
    return head;
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
    //traversal(head);
    int k;
    cin >> k;
    head = rotateRight(head,k);
    traversal(head);
    return 0;
}