//Kth Smallest Element in a BST
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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

node *createbst(node *root, int data)
{
    if (!root)
    {
        return new node(data);
    }
    else if (root->val > data)
    {
        root->left = createbst(root->left, data);
    }
    else
    {
        root->right = createbst(root->right, data);
    }
    return root;
}

//Method1: Using Inorder Traversal 
//T.C->O(N) && S.C->O(N)
void inorder(node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}
int kthSmallest(node *root, int k)
{
    vector<int> v;
    inorder(root, v);
    return v[k - 1];
}

//Method2: Using Stacks
//T.C->O(log(N)) && S.C->O(log(N))
int kthSmallest(node *root, int k)
{
    stack<node *> st;
    while (true)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        node *t = st.top();
        st.pop();
        if (--k == 0)
            return t->val;
        root = t->right;
    }
    return 0;
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
        root = createbst(root, data);
    }
}