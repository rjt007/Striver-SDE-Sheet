//PreOrder Traversal
//https://leetcode.com/problems/binary-tree-preorder-traversal/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left,*right;
    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

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

/* //Method1: Recursive
//T.C->O(N) && S.C->O(N)
void preorderTraversal(node* root)
{
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
} */

/* //Method2: Iterative
//T.C->O(N) && S.C->O(N)
void preorderTraversal(node *root)
{
    if (root == NULL) return;
    stack<node *> st;
    node *temp = root;
    while (temp != NULL || !st.empty())
    {
        while (temp != NULL)
        {
            cout<<temp->val<<" ";
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        temp = temp->right;
    }
} */

//Method3: Morris Traversal
//T.C->O(N)(Amortized) && S.C->O(1)
void preorderTraversal(node *root)
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
                cout<<curr->val<<" ";
                curr = curr->left;
            }
            else if(prev->right==curr)
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
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
    preorderTraversal(root);
}