#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left,*right;
    node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

node* createbst(node* root, int val){
    if(root==NULL) return new node(val);
    else if(root->val>val){
        root->left = createbst(root->left,val);
    }
    else{
        root->right = createbst(root->right,val);
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
        if(temp) cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main(){
    int n;
    cin>>n;
    node* root = NULL;
    int val;
    while (n--)
    {
        cin>>val;
        root = createbst(root,val);
    }
    bfstraversal(root);
}