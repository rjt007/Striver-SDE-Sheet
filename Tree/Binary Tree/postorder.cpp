//PostOrder Traversal
//https://leetcode.com/problems/binary-tree-postorder-traversal/
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
void postorderTraversal(node* root)
{
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
} */

/* //Method2: Using 2 Stacks
//T.C->O(N) && S.C->O(2*N)

void postorderTraversal(node* root)
{
    if(root==NULL) return;
    stack<node*>s1,s2;
    s1.push(root);
    while (!s1.empty())
    {
        node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left!=NULL) s1.push(temp->left);
        if(temp->right!=NULL) s1.push(temp->right);
    }
    while (!s2.empty())
    {
        cout<<s2.top()->val<<" ";
        s2.pop();
    }
} */

//Method3: Using 1 Stack
//T.C->O(N) && S.C->O(N)

void postorderTraversal(node* root)
{
    if(root==NULL) return;
    stack<node*>st;
    node* curr = root;
    while (!st.empty() || curr!=NULL)
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            node* temp = st.top()->right;
            if(temp==NULL)
            {
                temp = st.top();
                st.pop();
                cout<<temp->val<<" ";
                while (!st.empty() && temp==st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout<<temp->val<<" ";
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
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
    postorderTraversal(root);
}