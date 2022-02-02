//Count Complete Tree Nodes
//https://leetcode.com/problems/count-complete-tree-nodes/
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

//Method1: Using Simple BFS
//T.C->O(N) && S.C->O(N)
int countNodes(node *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
            ans++;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return ans;
}

//Method2: Using Recursion and Complete Binary Tree Property
//T.C->O((logN)^2) && S.C->O(logN)
int leftheight(node *root)
{
    int h = 0;
    while (root)
    {
        h++;
        root = root->left;
    }
    return h;
}

int rightheight(node *root)
{
    int h = 0;
    while (root)
    {
        h++;
        root = root->right;
    }
    return h;
}

int countNodes(node *root)
{
    if (root == NULL)
        return 0;
    int lh = leftheight(root);
    int rh = rightheight(root);
    if (lh == rh)
        return pow(2, lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
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
    int ans = countNodes(root);
    cout<<"Total Nodes are: "<<ans<<endl;
}