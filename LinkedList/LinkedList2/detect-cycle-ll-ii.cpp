//Linked List Cycle-ii
//https://leetcode.com/problems/linked-list-cycle-ii/

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

/* //Method1: Using Hashing
//T.C->O(N) & S.C->O(N)
node *detectCycle(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    unordered_set<node *> st;
    node *temp = head;
    while (temp != NULL)
    {
        if (st.find(temp) != st.end())
        {
            return temp;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return NULL;
}
 */
//Method: Using Fast & Slow Pointer
//T.C->O(N) & S.C->O(1)
node *detectCycle(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head, *fast = head;
    int t = 0;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            t = 1;
            break;
        }
    }
    if (t == 0)
    {
        return NULL;
    }
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
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
    node* cycle = detectCycle(head);
    return 0;
}