//INORDER TRAVERSAL OF BINARY TREE
//https://leetcode.com/problems/binary-tree-inorder-traversal/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node* left, *right;
    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

node* bfsinsertion(node* root, int data)
{
    if(root==NULL)
    {
        return new node(data);
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp->left==NULL)
        {
            temp->left = new node(data);
            return root;
        }
        else if(temp->right==NULL)
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
//T.C->O(N) & S.C->O(N)
void inorderTraversal(node* root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
} */

/* //Method2: Using Stack
//T.C->O(N) & S.C->O(N)
void inorderTraversal(node *root)
{
    if (root == NULL) return;
    stack<node*> st;
    node*temp = root;
    while (temp != NULL || !st.empty())
    {
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout<<temp->val<<" ";
        temp = temp->right;
    }
} */

//Method3: Morris Traversal
//T.C->O(N)(Amortized) && S.C->O(1)

void inorderTraversal(node* root)
{
    if(root==NULL) return;
    node* curr = root;
    while (curr!=NULL)
    {
        if(curr->left==NULL)
        {
            cout<<curr->val<<" ";
            curr = curr->right;
        }
        else
        {
            node* prev = curr->left;
            while (prev->right!=NULL && prev->right!=curr)
            {
                prev = prev->right;
            }

            if(prev->right==NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else if(prev->right==curr)
            {
                prev->right=NULL;
                cout<<curr->val<<" ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    node* root = NULL;
    int data;
    while(n--)
    {
        cin>>data;
        root = bfsinsertion(root,data);
    }
    inorderTraversal(root);
}