//Intersection of Two Linked Lists
//https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void traversal(node* head)
{
    node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

/* //Method1: Brute Force
//T.C->O(N^2) & S.C->O(1)
node *getIntersectionNode(node *headA, node *headB)
{
    while (headA != NULL)
    {
        node *ptrB = headB;
        while (ptrB != NULL)
        {
            if (headA == ptrB)
            {
                return ptrB;
            }
            ptrB = ptrB->next;
        }
        headA = headA->next;
    }
    return NULL;
} */

/* //Method2: Using Hashing
//T.C->O(N+M) && S.C->O(N)
node *getIntersectionNode(node *headA, node *headB)
{
    unordered_set<node *> st;
    while (headA != NULL)
    {
        st.insert(headA);
        headA = headA->next;
    }
    while (headB != NULL)
    {
        if (st.find(headB) != st.end())
        {
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
} */

/* //Method3: Using Implementation
//T.C->O(2*N) & S.C->O(1)
node *getIntersectionNode(node *headA, node *headB)
{
    node *pA = headA, *pB = headB;
    int lA = 0, lB = 0;
    while (pA != NULL || pB != NULL)
    {
        if (pA != NULL)
        {
            lA++;
            pA = pA->next;
        }
        if (pB != NULL)
        {
            lB++;
            pB = pB->next;
        }
    }
    int diff = 0;
    if (lA > lB)
    {
        diff = lA - lB;
        pA = headA;
        pB = headB;
    }
    else
    {
        diff = lB - lA;
        pB = headA;
        pA = headB;
    }

    while (diff--)
    {
        pA = pA->next;
        if (pA == NULL)
        {
            return NULL;
        }
    }

    while (pA != NULL && pB != NULL)
    {
        if (pA == pB)
        {
            return pA;
        }
        pA = pA->next;
        pB = pB->next;
    }
    return NULL;
}
 */

//Method4: Slight Modification Over Method3
//Using two dummy nodes
//T.C->O(2*N) & S.C->O(1)
node *getIntersectionNode(node *headA, node *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    node *p1 = headA, *p2 = headB;
    while (p1 != p2)
    {
        if (p1 == NULL)
        {
            p1 = headB;
        }
        else
        {
            p1 = p1->next;
        }
        if (p2 == NULL)
        {
            p2 = headA;
        }
        else
        {
            p2 = p2->next;
        }
    }
    return p1;
}

int main()
{
    int n;
    cin>>n;
    node* head1 = NULL;
    node* head2 = NULL;
    node* head3 = NULL;
    for (int i = 0; i < n; i++)
    {
        insertion(head1);
    }
    for (int i = 0; i < n; i++)
    {
        insertion(head2);
    }
    for (int i = 0; i < n; i++)
    {
        insertion(head3);
    }
    node *p1 = head1;
    while (p1->next!= NULL)
    {
        p1 = p1->next;
    }
    node *p2 = head2;
    while (p2->next!= NULL)
    {
        p2 = p2->next;
    }
    p1->next = head3;
    p2->next = head3;
    traversal(head1);
    traversal(head2);
    traversal(head3);

    node* intersection = getIntersectionNode(head1,head2);
    cout<<"Intersection Node is: ";
    traversal(intersection);
    return 0;
}