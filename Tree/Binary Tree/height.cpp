//Height of Binary Tree OR Maximum-Depth of Binary Tree
//https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
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

/* //Method1: Using Recursion
//T.C->O(N) && S.C->O(N)

int height(node* root)
{
    if(root==NULL) return -1; //height of empty tree
    int l = height(root->left);
    int r = height(root->right);
    return 1+max(l,r);
} */

//Method2: Using Iteration(BFS)
//T.C->O(N) && S.C->O(N)

int height(node* root)
{
    if(root==NULL) return -1; //height of empty tree
    int level=0;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp!=NULL){
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        else if(!q.empty()){
            level++;
            q.push(NULL);
        }  
    }
    return level;
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
    int h = height(root);
    cout<<"Height is: "<<h<<endl;
    return 0;
}
