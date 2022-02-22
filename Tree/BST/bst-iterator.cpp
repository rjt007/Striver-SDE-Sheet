//BST ITERATOR
//https://leetcode.com/problems/binary-search-tree-iterator/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
/* //
//Method1: Using Vector
//T.C->O(N) && S.C->O(N)
vector<int> v;
int i = 0;
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}

BSTIterator(TreeNode *root)
{
    inorder(root);
}

//T.C->O(1)
int next()
{
    return v[i++];
}
//T.C->O(1)
bool hasNext()
{
    if (i < v.size())
        return true;
    return false;
} */
//

//Method2: Using Stack and Inorder property
//T.C->O(1) && S.C->O(1) both are Amortized

stack<TreeNode *> st;

BSTIterator(TreeNode *root)
{
    pushleft(root);
}

int next()
{
    TreeNode *temp = st.top();
    st.pop();
    if (temp->right)
        pushleft(temp->right);
    return temp->val;
}

bool hasNext()
{
    return !st.empty();
}

void pushleft(TreeNode *root)
{
    if (root == NULL)
        return;
    while (root)
    {
        st.push(root);
        root = root->left;
    }
}

int main()
{
    return 0;
}