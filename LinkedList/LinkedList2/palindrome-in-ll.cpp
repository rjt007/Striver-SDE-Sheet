//Palindrome Linked List
//https://leetcode.com/problems/palindrome-linked-list/submissions/
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

/* //Method1: Using Stack;
//T.C->O(2*N) & S.C->O(N)
bool isPalindrome(node *head)
{
    stack<int> st;
    node *p = head, *q = head;
    while (p != NULL)
    {
        st.push(p->data);
        p = p->next;
    }
    while (q != NULL)
    {
        if (q->data != st.top())
        {
            return false;
        }
        st.pop();
        q = q->next;
    }
    return true;
}
 */

//Method2: Using Fast & Slow Pointer
//T.C->O(1.5*N) & S.C->O(1)
node *reverseList(node *head)
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
}
bool isPalindrome(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    slow = slow->next;
    node *dummy = head;
    while (slow != NULL)
    {
        if (dummy->data != slow->data)
        {
            return false;
        }
        slow = slow->next;
        dummy = dummy->next;
    }
    return true;
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
    bool palindrome = isPalindrome(head);
    cout<<"Is palindrome? : "<<palindrome<<endl;
    return 0;
}