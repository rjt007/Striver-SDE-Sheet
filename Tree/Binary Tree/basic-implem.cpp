//BINARY TREE IMPLEMENTATION
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left,*right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//BFS INSERTION
node* bfsinsertion(node* root, int val)
{
    if(root==NULL) 
    {
        return new node(val);
    }
    queue<node*>q;
    q.push(root);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp->left==NULL)
        {
            temp->left = new node(val);
            return root;
        }
        else if(temp->right==NULL)
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
void bfstraversal(node* root)
{
    if(root==NULL) return;
    queue<node*>q;
    q.push(root);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp!=NULL) cout<<temp->data<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
} 

int main()
{
    int n;
    cin>>n;
    int val;
    node* root = NULL;
    while (n--)
    {
        cin>>val;
        root = bfsinsertion(root,val);
    }
    bfstraversal(root);
}