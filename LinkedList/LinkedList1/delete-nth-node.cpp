//Remove Nth Node From End of List
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

/* //Method1: By Calculating Length & deleting (length-n+1)th element from front;
//T.C->O(N) & S.C->O(1)
int length(node *head)
{
    int l = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        l++;
        ptr = ptr->next;
    }
    return l;
}
node*removeNthFromEnd(node *head, int n)
{
    if (head->next == NULL) //handling corner case
    {
        return NULL;
    }
    node *p1 = head, *p2 = head->next;
    int l = length(head);
    if (n == 1) //deleting last node.
    {
        while (p1->next->next != NULL)
        {
            p1 = p1->next;
        }
        p1->next = NULL;
        return head;
    }
    if (n == l)//deleting front/head node.
    {
        head = p2;
        return head;
    }
    //for deleting node in middle.
    int l1 = l - n - 1;
    while (l1--)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = p2->next;
    return head;
}
 */

//Method2: Using fast & slow pointer
//T.C->O(N),single pass & S.C->O(1)
node *removeNthFromEnd(node *head, int n)
{
    if (head->next == NULL)
    {
        return NULL;
    }
    node *dummy = new node(-1);
    dummy->next = head;
    node *slow = dummy, *fast = dummy;
    while (n--)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
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
    int nth;
    cin>>nth;
    node* deletion = removeNthFromEnd(head,nth);
    traversal(deletion);
    return 0;
}