//AllInOneOrder Traversal
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
        else if (temp->right == NULL)
        {
            temp->right = new node(data);
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

//Method: Using A Stack
//T.C->O(3*N) && S.C->O(3*N)

vector<int> pre, in, post;
void allInOneorderTraversal(node* root)
{
    if (root == NULL) return;
    stack<pair<node*,int>>st;
    st.push({root,1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if(it.second==1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL)
            {
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL)
            {
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->val);
        }
    }
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
    allInOneorderTraversal(root);
    for (int i = 0; i < pre.size(); i++)
    {
        cout<<pre[i]<<" ";
    }
    cout << endl;
    for (int i = 0; i < in.size(); i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < post.size(); i++)
    {
        cout<<post[i]<<" ";
    }
    cout << endl;
    return 0;
}