//Ceil and Floor Value in BST
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

//BST INSERTION
node *bstinsertion(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }
    else if (data < root->val)
    {
        root->left = bstinsertion(root->left, data);
    }
    else
    {
        root->right = bstinsertion(root->right, data);
    }
    return root;
}

//Method: Using Iteration
//T.C->O(log(n)) & S.C->O(1)
int ceil(node* root, int key){
    int cl = -1;
    if(root==NULL) cl;
    while(root){
        if(root->val==key){
            cl = root->val;
            return cl;
        }
        else if(root->val>key){
            cl = root->val;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return cl;
}

//Method: Using Iteration
//T.C->O(log(n)) & S.C->O(1)
int floor(node* root, int key){
    int fl = -1;
    if(root==NULL) fl;
    while(root){
        if(root->val==key){
            fl = root->val;
            return fl;
        }
        else if(root->val<key){
            fl = root->val;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return fl;
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
        root = bstinsertion(root, data);
    }
    int key;
    cin >> key;
    int cl = ceil(root, key);
    cout << "Ceil value of key is: " << cl << endl;
    int fl = floor(root, key);
    cout << "Floor value of key is: " << fl << endl;
}