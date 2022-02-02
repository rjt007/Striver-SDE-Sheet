//Children Sum Property
//https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723
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

void bfstraversal(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
            cout << temp->val << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

//Method: DFS Traversal
//T.C->O(N) && S.C->O(H)
void childsum(node* root){
    if(root==NULL) return;
    int child = 0;
    if(root->left){
        child+=root->left->val;
    }
    if(root->right){
        child+=root->right->val;
    }
    if(child>=root->val){
        root->val = child;
    }
    else{
        if (root->left)
        {
            root->left->val = root->val;
        }
        if (root->right)
        {
            root->right->val = root->val;
        }
    }

    childsum(root->left);
    childsum(root->right);

    int total = 0;
    if (root->left)
    {
        total+= root->left->val;
    }
    if (root->right)
    {
        total+= root->right->val;
    }
    if (root->left || root->right)
    {
        root->val = total;
    }
}

int main()
{
    int n;
    cin >> n;
    int data;
    node *root = NULL;
    while (n--)
    {
        cin >> data;
        root = bfsinsertion(root, data);
    }
    bfstraversal(root);
    childsum(root);
    cout<<endl;
    bfstraversal(root);
}