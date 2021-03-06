//Path to Given Node
//https://www.interviewbit.com/problems/path-to-given-node/
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
//Method: Using preorder traversal
//T.C->O(N) & S.C->O(N) 
bool preorder(node *root, int n, vector<int> &ans)
{
    if (root == NULL)
        return false;
    ans.push_back(root->val);
    if (root->val == n)
    {
        return true;
    }
    if (preorder(root->left, n, ans) || preorder(root->right, n, ans))
        return true;
    ans.pop_back();
    return false;
}

vector<int> solve(node *root, int n)
{
    vector<int> ans;
    preorder(root, n, ans);
    return ans;
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
    int d;
    cin>>d;
    vector<int> ans = solve(root,d);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}