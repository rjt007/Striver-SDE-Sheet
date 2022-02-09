//https://leetcode.com/problems/inorder-successor-in-bst/
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
//Method: Using BST prop && Iteration
//T.C->O(log(N)) && S.C->O(1)
TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
{
    TreeNode *successor = NULL;

    while (root != NULL)
    {

        if (p->val >= root->val)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root = root->left;
        }
    }

    return successor;
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