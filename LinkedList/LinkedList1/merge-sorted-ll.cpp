//Merge Two Sorted Lists
//https://leetcode.com/problems/merge-two-sorted-lists/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
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
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* //Method1: Using Two Pointers
//T.C->O(3*N) && S.C->O(N)
node *mergeTwoLists(node *l1,node *l2)
{
    node *p1 = l1;
    node *p2 = l2;
    node *dummy = new node(-1);
    node *p3 = dummy;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}
 */

//Method2: In Place Sorting
//T.C->O(N1+N2) && S.C->O(1)
node *mergeTwoLists(node *&l1,node *&l2)
{
    if (l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    if(l1->data>l2->data)
    {
        swap(l1,l2);
    }
    node* res = l1;
    while (l1!=NULL && l2!=NULL)
    {
           node* temp = NULL;
           while(l1!=NULL && l1->data <= l2->data)
           {
               temp = l1;
               l1 = l1->next;
           }
           temp->next = l2;
           swap(l1,l2);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    node *head1 = NULL;
    node *head2 = NULL;
    for (int i = 0; i < n; i++)
    {
        insertion(head1);
    }
    for (int i = 0; i < n; i++)
    {
        insertion(head2);
    }
    traversal(head1);
    traversal(head2);
    node* newnode = mergeTwoLists(head1,head2);
    traversal(newnode);
    return 0;
}