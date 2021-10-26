//Add Two Numbers
//https://leetcode.com/problems/add-two-numbers/
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

//Method: Using Mathematics & Implementation
//T.C->O(max(n,m)) && S.C->O(max(n,m))

node *addTwoNumbers(node *l1, node *l2)
{
    node *dummy = new node(-1);
    node *temp = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        node *newnode = new node(sum % 10);
        temp->next = newnode;
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{
    int n,m;
    cin >> n>>m;
    node *head1 = NULL, *head2 = NULL;
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
    node* addition = addTwoNumbers(head1,head2);
    traversal(addition);
    return 0;
}