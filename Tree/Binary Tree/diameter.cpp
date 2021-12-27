//Diameter of Binary Tree
//https://leetcode.com/problems/diameter-of-binary-tree/
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
        else if (temp->right == NULL)
        {
            temp->right = new node(data);
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

/* //Method1: Brute Force
//T.C->O(N^2) && S.C->O(N)

int height(node* root)
{
    if(root==NULL) return 0; //height of empty tree
    int l = height(root->left);
    int r = height(root->right);
    return 1+max(l,r);
}


void diameter(node* root, int &dia)
{
    if(root==NULL) return;
    int lh = height(root->left);
    int rh = height(root->right);
    dia = max(dia,lh+rh);
    diameter(root->left,dia);
    diameter(root->right,dia);
} */

//Method2: Optimization Over Height
//T.C->O(N) && S.C->O(N)

int diameter(node* root, int &dia){
    if(root==NULL) return 0;
    int lh = diameter(root->left,dia);
    int rh = diameter(root->right,dia);
    dia = max(dia,lh+rh);
    return 1+max(lh,rh);
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
    int dia=0;
    diameter(root,dia);
    cout << "Diameter is: " << dia << endl;
    return 0;
}
