//Insert into a Binary Search Tree
//https://leetcode.com/problems/insert-into-a-binary-search-tree/
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

//Method: Using simple Iteration
//T.C->O(log(N)) && S.C->O(1)
node *insertIntoBST(node *root, int val)
{
    if (root == NULL)
        return root = new node(val);
    node *newnode = new node(val);
    node *temp = root;
    node *temp2 = NULL;
    while (temp)
    {
        temp2 = temp;
        if (temp->val > val)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp2->val > val)
    {
        temp2->left = newnode;
    }
    else
    {
        temp2->right = newnode;
    }
    return root;
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
}