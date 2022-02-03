//Search in a Binary Search Tree
//https://leetcode.com/problems/search-in-a-binary-search-tree/
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

//BST INSERTION
node *bstinsertion(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }
    else if (data < root->val)
    {
        root->left = bstinsertion(root->left, data);
    }
    else
    {
        root->right = bstinsertion(root->right, data);
    }
    return root;
}

//Method: Using DFS
// T.C->O(log(N)) && S.C->O(H)
bool searchinbst(node* root, int key){
    if(root==NULL) return false;
    if(root->val==key) return true;
    else{
        if(root->val>key) return searchinbst(root->left,key);
        else return searchinbst(root->right,key);
    }
    return false;
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
        root = bstinsertion(root, data);
    }
    int key;
    cin>>key;
    bool ans = searchinbst(root,key);
    cout<<"1 if key is found: "<<ans<<endl;
}