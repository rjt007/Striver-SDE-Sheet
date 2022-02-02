//Construct Binary Tree from Preorder and Inorder Traversal
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
node *makeTree(vector<int> &preorder, int prestart, int preend, vector<int> &inorder,
                   int instart, int inend, map<int, int> &mp)
{

    if (prestart > preend || instart > inend)
        return NULL;

    node *root = new node(preorder[prestart]);
    int in_root_idx = mp[root->val];
    int numleft = in_root_idx - instart;
    root->left = makeTree(preorder, prestart + 1, prestart + numleft,
                          inorder, instart, in_root_idx - 1, mp);
    root->right = makeTree(preorder, prestart + numleft + 1, preend,
                           inorder, in_root_idx + 1, inend, mp);

    return root;
}

node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    node *root = makeTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
}

void preorderTraversal(node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    int n;
    cin >> n;
    node *root = NULL;
    vector<int>inorder(n,0),preorder(n,0);
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    root = buildTree(preorder, inorder);
    preorderTraversal(root);
    return 0;
}