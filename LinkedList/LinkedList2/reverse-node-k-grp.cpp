//Reverse Nodes in k-Group
//https://leetcode.com/problems/reverse-nodes-in-k-group/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
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
    node* newnode = new node(val);
    if(head==NULL)
    {
        head = newnode;
        return;
    }
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void traversal(node* head)
{
    node* ptr = head;
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

//Method: Iteration
//T.C->O(2*N) & S.C->O(1)

node *reverseKGroup(node *head, int k)
{
    if (head == NULL || k == 1)
    {
        return head;
    }

    int l = 0;
    node *p = head;
    while (p != NULL)
    {
        l++;
        p = p->next;
    }

    node *dummy = new node(0);
    dummy->next = head;
    node *prev = dummy, *curr = dummy, *nex = dummy;
    while (l >= k)
    {
        curr = prev->next;
        nex = curr->next;
        for (int i = 1; i < k; i++)
        {
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        prev = curr;
        l -= k;
    }
    return dummy->next;
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
    int k;
    cin>>k;
    head = reverseKGroup(head,k);
    traversal(head);
    return 0;
}