//Bottom View of Binary Tree
//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
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

//Method: Using BFS and Vertical Order Traversal Concepts
//Bottom View is exactly the Top-View with only one line code change.
//T.C->O(N) && S.C->O(N)
vector<int> bottomView(node *root)
{
    //Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<int, node *>> q;
    q.push({0, root});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int vertical = it.first;
        node *temp = it.second;
        mp[vertical] = temp->val;

        if (temp->left != NULL)
            q.push({vertical - 1, temp->left});
        if (temp->right != NULL)
            q.push({vertical + 1, temp->right});
    }
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
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
    vector<int> ans = bottomView(root);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}