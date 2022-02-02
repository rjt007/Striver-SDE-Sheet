//Maximum Width of Binary Tree
//https://leetcode.com/problems/maximum-width-of-binary-tree/
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
//Method: Using BFS Traversal & Segment tree concept
//T.C->O(N) && S.C->O(N)
int widthOfBinaryTree(node *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int minidx = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int curridx = q.front().second - minidx;
            node *temp = q.front().first;
            q.pop();
            if (i == 0)
                first = curridx;
            if (i == size - 1)
                last = curridx;
            if (temp->left != NULL)
            {
                q.push({temp->left, 2 * curridx + 1});
            }
            if (temp->right != NULL)
            {
                q.push({temp->right, 2 * curridx + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    node* root = NULL;
    int data;
    while (n--)
    {
        cin>>data;
        root = bfsinsertion(root,data);
    }
    int width = widthOfBinaryTree(root);
    cout<<"Max Width of Tree is: "<<width<<endl;
}