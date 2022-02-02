//Serialize and Deserialize Binary Tree
//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
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

//Method: Using BFS Traversal
//T.C->O(N) && S.C->O(N)

// Encodes a tree to a single string.
string serialize(node *root)
{
    string serial = "";
    if (root == NULL)
        return serial;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
            serial.append(to_string(temp->val) + ',');
        else
            serial.append("#,");
        if (temp != NULL)
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    cout << serial << endl;
    return serial;
}

// Decodes your encoded data to tree.
node *deserialize(string data)
{
    if (data == "")
        return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');
    node *root = new node(stoi(str));
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
        {
            temp->left = NULL;
        }
        else
        {
            temp->left = new node(stoi(str));
            q.push(temp->left);
        }
        getline(s, str, ',');
        if (str == "#")
        {
            temp->right = NULL;
        }
        else
        {
            temp->right = new node(stoi(str));
            q.push(temp->right);
        }
    }
    return root;
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
    string ans = serialize(root);
    cout<<ans<<endl;
}