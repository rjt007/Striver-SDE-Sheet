//Lowest Common Ancestor of a Binary Search Tree
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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

//BST INSERTION
node *bstinsertion(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }
    else if (data < root->val)
    {
        root->left = bstinsertion(root->left, data);
    }
    else
    {
        root->right = bstinsertion(root->right, data);
    }
    return root;
}

//Method1: Using REcursion as we used in lca of Binary Tree
// T.C->O(N) && S.C->O(N)
node *lowestCommonAncestor(node *root, node *p, node *q)
{
    if (root == NULL || root == p || root == q)
        return root;
    node *leftnode = lowestCommonAncestor(root->left, p, q);
    node *rightnode = lowestCommonAncestor(root->right, p, q);
    if (leftnode == NULL)
        return rightnode;
    else if (rightnode == NULL)
        return leftnode;
    else
        return root;
}

//Method2: Using BST Property
//T.C->O(log(N)) && S.C->O(log(N))
node *lowestCommonAncestor(node *root, node *p, node *q)
{
    if (!root)
        return NULL;
    int curr = root->val;
    if (curr < p->val && curr < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    if (curr > p->val && curr > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}

//Method3: Using Iteration and BST property
//T.C->O(log(N)) && S.C->O(1)
node *lowestCommonAncestor(node *root, node *p, node *q)
{
    node *temp = root;
    while (temp)
    {
        if (temp->val > p->val && temp->val > q->val)
        {
            temp = temp->left;
        }
        else if (temp->val < p->val && temp->val < q->val)
        {
            temp = temp->right;
        }
        else
        {
            return temp;
        }
    }
    return temp;
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
        root = bstinsertion(root, data);
    }
    bfstraversal(root);
}