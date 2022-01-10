//Lowest Common Ancestor of a Binary Tree
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
//Method1: Using Root to Node path logic
//T.C->O(2*N) & S.C->O(2*N)
bool preorder(node *root, node *n, vector<node *> &ans)
{
    if (root == NULL)
        return false;
    ans.push_back(root);
    if (root == n)
    {
        return true;
    }
    if (preorder(root->left, n, ans) || preorder(root->right, n, ans))
        return true;
    ans.pop_back();
    return false;
}
node *lowestCommonAncestor(node *root, node *p, node *q)
{
    vector<node *> pv;
    vector<node *> qv;
    node *ans;
    preorder(root, p, pv);
    preorder(root, q, qv);
    int n = min(pv.size(), qv.size());
    for (int i = 0; i < n; i++)
    {
        if (pv[i] == qv[i])
        {
            ans = pv[i];
        }
    }
    return ans;
}

//Method2: Using DFS traversal
//T.C->O(N) && S.C->O(N)
node *lowestCommonAncestor(node *root, node *p, node *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    node *leftnode = lowestCommonAncestor(root->left, p, q);
    node *rightnode = lowestCommonAncestor(root->right, p, q);

    if (leftnode == NULL)
        return rightnode;
    else if (rightnode == NULL)
        return leftnode;
    else
    {
        return root;
    }
}

int main()
{
    int n;
    cin >> n;
    node *root = NULL;
    int data;
    while (n--)
    {
        cin >> data;
        root = bfsinsertion(root, data);
    }
}