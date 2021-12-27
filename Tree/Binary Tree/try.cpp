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
    while (!q.empty())
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
        else{
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return root;
}

vector<vector<int>> bfstraversal(node* root)
{
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    vector<int>preans;
    int flag = 0;
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp!=NULL){
            preans.push_back(temp->val);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        else if(!q.empty()){
            if(flag==0){
                ans.push_back(preans);
                flag = 1;
            } 
            else if(flag==1){
                reverse(preans.begin(),preans.end());
                ans.push_back(preans);
                flag = 0;
            }
            preans.clear();
            q.push(NULL);
        }
    }
    if(flag==0){
        ans.push_back(preans);
    }
    else{
        reverse(preans.begin(), preans.end());
        ans.push_back(preans);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    node* root = NULL;
    int data;
    while (n--)
    {
        cin>>data;
        root = bfsinsertion(root,data);
    }
    vector<vector<int>>ans = bfstraversal(root);
    for(auto x:ans){
        for (int i = 0; i < x.size(); i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
}