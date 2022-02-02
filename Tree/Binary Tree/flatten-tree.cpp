//Flatten Binary Tree to Linked List
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left, *right;
    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

node *bfsinsertion(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = new node(data);
            return root;
        }
        if (temp->right == NULL)
        {
            temp->right = new node(data);
            return root;
        }
        q.push(temp->left);
        q.push(temp->right);
    }
    return root;
}

//Method1: Using Reverse Postorder
//T.C->O(N) && S.C->O(N)
node* prev = NULL;
void flatten(node *root)
{
    if (root == NULL)
        return;
    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

//Method2: Using Stack
//T.C->O(N) && S.C->O(N)
void flatten(node *root)
{
    if (root == NULL)
        return;
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
        if (!st.empty())
        {
            temp->right = st.top();
        }
        temp->left = NULL;
    }
}

//Method3: Using Morrsih Traversal 
//T.C->O(N){Amortized} && S.C->O(1)
void flatten(node *root)
{
    node *cur = root;
    while (cur)
    {
        if (cur->left)
        {
            node *pre = cur->left;
            while (pre->right)
            {
                pre = pre->right;
            }
            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}

int main()
{
    int n;
    cin >> n;
    int data;
    node *root = NULL;
    while (n--)
    {
        cin >> data;
        root = bfsinsertion(root, data);
    }
    bfstraversal(root);
}