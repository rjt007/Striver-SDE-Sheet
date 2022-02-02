#include<bits/stdc++.h>
using namespace std;

struct node
{
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
    while(!q.empty()){
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

void bfstraversal(node* root){
    if(root==NULL) return;
    queue<node*>q;
    q.push(root);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp!=NULL) cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
}
int main(){
    int n;
    cin>>n;
    int data;
    node* root = NULL;
    while (n--)
    {
        cin>>data;
        root = bfsinsertion(root,data);
    }
    bfstraversal(root);
}