//Delete Node in a BST
//https://leetcode.com/problems/delete-node-in-a-bst/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left, *right;
    node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

node* createbst(node* root, int data){
    if(!root){
        return new node(data);
    }
    else if(root->val>data){
        root->left = createbst(root->left,data);
    }
    else{
        root->right = createbst(root->right,data);
    }
    return root;
}

//Method: Using Recursion
//T.C->O(log(N)) && S.C->O(log(n))

node *inordersuccesor(node *root)
{
    if (root == NULL)
        return NULL;
    else if (!root->left)
        return root;
    return inordersuccesor(root->left);
}
node *deleteNode(node *root, int key)
{
    if (root == NULL)
        return root;
    else if (root->val > key)
        root->left = deleteNode(root->left, key);
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    //key found
    else
    {
        if (!root->left && !root->right) //Case1
        {
            delete root;
            return NULL;
        }
        else if (!root->left) //Case2-part1
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) //Case2-part2
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        //Case3
        //using inorder succesor - finding min in right sub tree.
        else  
        {
            TreeNode *temp = inordersuccesor(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

int main(){
    int n;
    cin>>n;
    int data;
    node* root = NULL;
    while (n--)
    {
        cin>>data;
        root = createbst(root,data);
    }
    
}