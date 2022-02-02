//All Nodes Distance K in Binary Tree
//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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

//Method: Using BFS Traversal
//T.C->O(2*N) && S.C->O(3*N)
void connectparent(node *root, unordered_map<node *, node *> &parent)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            parent[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            parent[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

vector<int> distanceK(node *root, node *target, int k)
{
    unordered_map<node *, node *> parent;
    connectparent(root, parent);

    unordered_map<node *, bool> visited;
    queue<node *> q;
    q.push(target);
    visited[target] = true;
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (level++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if (parent[temp] != NULL && !visited[parent[temp]])
            {
                q.push(parent[temp]);
                visited[parent[temp]] = true;
            }
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
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
}