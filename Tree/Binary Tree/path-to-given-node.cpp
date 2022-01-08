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
bool isleaf(node *root)
{
    return (root->left == NULL && root->right == NULL);
}
void preorder(node *root, int data, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->val == data)
    {
        ans.push_back(root->val);
        return;
    }
    else
    {
        if (!isleaf(root))
            ans.push_back(root->val);
        else if (isleaf(root) && root->val == data)
            ans.push_back(root->val);
    }
    preorder(root->left, data, ans);
    preorder(root->right, data, ans);
}
vector<int>solve(node *root, int data)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    preorder(root, data, ans);
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