//Construct Binary Tree from Postorder and Inorder Traversal
//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

//Method: Using Recursion
//T..C->O(N*log(N)) && S.C->O(N)
node *makeTree(vector<int> &postorder, int poststart, int postend,
                   vector<int> &inorder, int instart, int inend, map<int, int> &mp)
{

    if (poststart > postend || instart > inend)
        return NULL;

    node *root = new node(postorder[postend]);
    int in_root_idx = mp[root->val];
    int inleft = in_root_idx - instart;

    root->left = makeTree(postorder, poststart, poststart + inleft - 1,
                          inorder, instart, in_root_idx - 1, mp);
    root->right = makeTree(postorder, poststart + inleft, postend - 1,
                           inorder, in_root_idx + 1, inend, mp);
    return root;
}

node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    node *root = makeTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
}

void postorderTraversal(node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main()
{
    int n;
    cin >> n;
    node *root = NULL;
    vector<int> inorder(n, 0), postorder(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }
    root = buildTree(inorder,postorder);
    postorderTraversal(root);
    return 0;
}