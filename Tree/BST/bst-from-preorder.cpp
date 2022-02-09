//Construct Binary Search Tree from Preorder Traversal
//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
include <bits/stdc++.h>
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

//Method1: Brute Force
//T.C->O(N^2) && S.C->O(N)
TreeNode *bst(TreeNode *root, int data)
{
    if (!root)
        return new TreeNode(data);
    else if (root->val > data)
    {
        root->left = bst(root->left, data);
    }
    else
    {
        root->right = bst(root->right, data);
    }
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int n = preorder.size();
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = bst(root, preorder[i]);
    }
    return root;
}

//Method2: Using Preorder+Inorder
//T.C->O(N*log(N)) && S.C->O(N)
node *bst(vector<int> in, int instart, int inend,
              vector<int> pre, int prestart, int preend, unordered_map<int, int> mp)
{

    if (prestart > preend || instart > inend)
        return NULL;
    node *root = new node(pre[prestart]);
    int in_root_idx = mp[root->val];
    int inleft = in_root_idx - instart;
    int inright = inend - in_root_idx;

    root->left = bst(in, instart, in_root_idx - 1,
                     pre, prestart + 1, inleft + prestart, mp);
    root->right = bst(in, in_root_idx + 1, inend,
                      pre, inleft + prestart + 1, preend, mp);
    return root;
}

node *bstFromPreorder(vector<int> &preorder)
{
    vector<int> inorder(preorder);
    sort(inorder.begin(), inorder.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    node *root = NULL;
    root = bst(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, mp);
    return root;
}

//Method3: Using UpperBound Method
//T.C->O(3*N) && S.C->O(N)
node *bst(vector<int> &pre, int &i, int bound)
{
    if (i >= pre.size() || pre[i] > bound)
        return NULL;
    node *root = new node(pre[i++]);
    root->left = bst(pre, i, root->val);
    root->right = bst(pre, i, bound);
    return root;
}
node *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return bst(preorder, i, INT_MAX);
}
int main()
{
    int n;
    cin >> n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    node *root = bstFromPreorder(v);
}