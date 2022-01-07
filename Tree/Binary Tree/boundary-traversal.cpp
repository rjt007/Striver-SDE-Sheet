//Boundary Traversal
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
        if (temp->right == NULL)
        {
            temp->right = new node(data);
            return root;
        }
        q.push(temp->left);
        q.push(temp->right);
    }
    return root;
}


//T.C->O(2*H+N) && S.C->O(N), H->height of tree

bool isLeaf(node* root){
    if(root->left==NULL && root->right==NULL) return true;
    else return false;
}

void addLeftBoundary(node* root, vector<int>&res){
    node* temp = root->left;
    while (temp!=NULL)
    {
        if(!isLeaf(temp)) res.push_back(temp->val);
        if(temp->left!=NULL) temp = temp->left;
        else temp = temp->right;
    }
}
void addRightBoundary(node* root, vector<int>&res){
    node* temp = root->right;
    vector<int>v;
    while (temp!=NULL)
    {
        if(!isLeaf(temp)) v.push_back(temp->val);
        if(temp->right!=NULL) temp = temp->right;
        else temp = temp->left;
    }
    for (int i = v.size()-1; i >=0; i--)
    {
        res.push_back(v[i]);
    }
}
void addLeaves(node* root, vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left!=NULL) addLeaves(root->left,res);
    if(root->right!=NULL) addLeaves(root->right,res);
}

vector<int> boundaryTraversal(node *root)
{
    vector<int>res;
    if (!root) return res;

    if (!isLeaf(root)) res.push_back(root->val);

    //add left boundary
    addLeftBoundary(root, res);

    // add leaf nodes
    addLeaves(root, res);

    //add right boundary
    addRightBoundary(root, res);

    return res;
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
    vector<int>ans = boundaryTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}