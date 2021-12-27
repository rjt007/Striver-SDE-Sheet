//Zig-Zag or Spiral Order Traversal
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//BFS INSERTION
node *bfsinsertion(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = new node(val);
            return root;
        }
        else if (temp->right == NULL)
        {
            temp->right = new node(val);
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

//Method: Using BFS traversal
//T.C->O(N) & S.C->O(N)
vector<vector<int>> zigzagOrder(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<node *> q;
    q.push(root);
    bool lefttoright = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int>row(size);
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            int index = (lefttoright)?i:(size-i-1);
            row[index] = temp->data;
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
        //changing value at each level.
        lefttoright = !lefttoright;
        ans.push_back(row);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int val;
    node *root = NULL;
    while (n--)
    {
        cin >> val;
        root = bfsinsertion(root, val);
    }
    vector<vector<int>> ans = zigzagOrder(root);
    for (auto x : ans)
    {
        for (int i = 0; i < x.size(); i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}