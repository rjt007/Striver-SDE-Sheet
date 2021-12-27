//Balanced Binary Tree
//https://leetcode.com/problems/balanced-binary-tree/
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
        else if (temp->right == NULL)
        {
            temp->right = new node(data);
            return root;
        }
        else
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return root;
}

/* //Method1: Using Recursion
//T.C->O(N^2) && S.C->O(N)

int height(node* root)
{
    if(root==NULL) return -1; //height of empty tree
    int l = height(root->left);
    int r = height(root->right);
    return 1+max(l,r);
}

bool isBalanced(node *root)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1)
        return false;
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    if (!left || !right)
        return false;
    return true;
}
 */

//Method1: Using Recursion with Optimization in height
//T.C->O(N) && S.C->O(N)
int height(node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh == -1 || rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(node *root)
{
    return height(root) != -1;
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
    bool Isbalanced = isBalanced(root);
    cout << "Binary tree is Blanced: " << Isbalanced<< endl;
    return 0;
}
