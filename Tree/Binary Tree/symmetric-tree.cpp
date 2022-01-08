//Symmetric Tree
//https://leetcode.com/problems/symmetric-tree/
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

//Method: Using DFS traversal
//T.c->O(N) && S.C->O(N)
bool isSymmetricHelp(node *leftsubtree, node *rightsubtree)
{
    if (leftsubtree == NULL || rightsubtree == NULL)
        return leftsubtree == rightsubtree;
    if (leftsubtree->val != rightsubtree->val)
        return false;
    return isSymmetricHelp(leftsubtree->left, rightsubtree->right) 
        && isSymmetricHelp(leftsubtree->right, rightsubtree->left);
}

bool isSymmetric(node *root)
{
    if (root == NULL)
        return false;
    return isSymmetricHelp(root->left, root->right);
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
    isSymmetric(root);
}