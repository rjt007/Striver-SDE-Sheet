// 2-SUM
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

/* //Method1: Using Vector
//T.C->O(N) && S.C->O(N)
class Solution
{
public:
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode *root, int k)
    {
        inorder(root);
        int n = v.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (v[i] + v[j] == k)
            {
                return true;
            }
            else if (v[i] + v[j] < k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
}; */

//Method2: Using BST Iterator Property 
//T.C->O(N) && S.C->O(log(N))

class BSTIterator
{
public:
    stack<TreeNode *> st;
    bool reverse = true;

    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        if (reverse)
        {
            if (temp->right)
                pushAll(temp->right);
        }
        else
        {
            if (temp->left)
                pushAll(temp->left);
        }
        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void pushAll(TreeNode *root)
    {
        if (root == NULL)
            return;
        while (root)
        {
            st.push(root);
            if (reverse)
                root = root->left;
            else
                root = root->right;
        }
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        BSTIterator *nex = new BSTIterator(root, true);
        BSTIterator *bef = new BSTIterator(root, false);
        int i = nex->next();
        int j = bef->next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = nex->next();
            else
                j = bef->next();
        }
        return false;
    }
};