//Vertical Order Traversal of a Binary Tree
//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left, *right;
    node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

node* bfsinsertion(node* root, int data){
    if(root==NULL){
        return new node(data);
    }
    queue<node*>q;
    q.push(root);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp->left==NULL){
            temp->left = new node(data);
            return root;
        }
        if(temp->right==NULL){
            temp->right = new node(data);
            return root;
        }
        q.push(temp->left);
        q.push(temp->right);
    }    
    return root;
}


//Method: BFS and Map concepts
//T.C->O(N*log(N)) && S.C->O(3*N)
vector<vector<int>> verticalTraversal(node *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        node *temp = p.first;
        int vertical = p.second.first;
        int level = p.second.second;
        mp[vertical][level].insert(temp->val);
        if (temp->left)
        {
            q.push({temp->left, {vertical - 1, level + 1}});
        }
        if (temp->right)
        {
            q.push({temp->right, {vertical + 1, level + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto t1 : mp)
    {
        vector<int> col;
        for (auto t2 : t1.second)
        {
            col.insert(col.end(), t2.second.begin(), t2.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    node* root = NULL;
    int data;
    while (n--)
    {
        cin>>data;
        root = bfsinsertion(root,data);
    }
    vector<vector<int>>ans = verticalTraversal(root);
    for (auto row: ans)
    {
        for (auto col:row)
        {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}