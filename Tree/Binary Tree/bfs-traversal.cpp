//Binary Tree Level Order Traversal
//https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//BFS INSERTION
node *bfsinsertion(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = new node(val);
            return root;
        }
        else if (temp->right == NULL)
        {
            temp->right = new node(val);
            return root;
        }
        else
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return root;
}

//BFS TRAVERSAL
//T.C->O(N) & S.C->O(N)
vector<vector<int>> levelOrder(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int val;
    node *root = NULL;
    while (n--)
    {
        cin >> val;
        root = bfsinsertion(root, val);
    }
    vector<vector<int>>ans = levelOrder(root);
    for (auto x:ans)
    {
        for (int i = 0; i <n; i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}