//Validate Binary Search Tree
//https://leetcode.com/problems/validate-binary-search-tree/
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

//Method1: Using Inorder Traversal
//T.C->O(2*N) && S.C->O(2*N)
void inorder(node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}
bool isValidBST(node *root)
{
    vector<int> v;
    inorder(root, v);
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] >= v[i + 1])
            return false;
    }
    return true;
}

//Method2: Using Recursion and Range property
//T.C->O(N) && Auxialry S.C->O(N)
bool checkBST(node *root, long long minval, long long maxval)
{
    if (root == NULL)
        return true;
    if (root->val <= minval || root->val >= maxval)
        return false;
    return checkBST(root->left, minval, root->val) && checkBST(root->right, root->val, maxval);
}

bool isValidBST(node *root)
{
    bool ans = checkBST(root, LONG_MIN, LONG_MAX);
    return ans;
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