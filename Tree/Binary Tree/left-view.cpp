//Left View of Binary Tree
//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
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

/* //Method: Using BFS Traversal
//T.C->O(N) && S.C->O(N)
vector<int> leftView(node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        node *temp = it.first;
        int level = it.second;
        if (mp.find(level) == mp.end())
            mp[level] = temp->val;
        if (temp->left != NULL)
            q.push({temp->left, level + 1});
        if (temp->right != NULL)
            q.push({temp->right, level + 1});
    }
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    return ans;
} */

//Method: Using DFS Traversal
//T.C->O(N) && S.C->O(H)
void dfs(node* root, int level, vector<int>&ans){
    if(root==NULL) return;
    if(ans.size()==level) ans.push_back(root->val);
    dfs(root->left,level+1,ans);
    dfs(root->right,level+1,ans);
}
vector<int> leftView(node *root){
    vector<int>ans;
    if(root==NULL) return ans;
    dfs(root,0,ans);
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
    vector<int> ans = leftView(root);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}