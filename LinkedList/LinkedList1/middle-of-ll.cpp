//Middle of the Linked List
//https://leetcode.com/problems/middle-of-the-linked-list/
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

/* //Method1: By Calculating Length
//T.C->O(N)+O(N/2) ~ O(N) && S.C->O(1)

int length(node* head)
{
    node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
node *middleNode(node *head)
{
    int l = length(head);
    int len = l / 2;
    node *temp = head;
    while (len--)
    {
        temp = temp->next;
    }
    return temp;
} */

//Method2: Using Fast & Slow Pointers
//T.C->O(N/2) & S.C->O(1)

node *middleNode(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    node* middle = middleNode(head);
    traversal(middle);
    return 0;
}