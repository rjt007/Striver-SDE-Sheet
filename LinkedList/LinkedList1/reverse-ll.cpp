//Reverse Linked List
//https://leetcode.com/problems/reverse-linked-list/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertion(node* &head)
{
    int val;
    cin>>val;
    node *newnode = new node(val);
    if(head==NULL)
    {
        head = newnode;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void traversal(node* head)
{
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
/* 
//Method1: Iterative
//T.C->O(N) && S.C->O(1)
node* reverseList(node* head)
{
    node *curr = NULL, *prev = NULL, *nxt = head;
    while (nxt != NULL)
    {
        curr = nxt;
        nxt = nxt->next;
        curr->next = prev;
        prev = curr;
    }
    head = curr;
    return head;
} */

//Method2: Recursive
//T.C->O(N) & S.C->O(1) , Auxilary S.C->O(N)
node *reverseList(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newnode = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newnode;
}

int main()
{
    int n;
    cin>>n;
    node* head = NULL;
    for (int i = 0; i < n; i++)
    {
        insertion(head);
    }
    traversal(head);
    head = reverseList(head);
    traversal(head);
    return 0;
}