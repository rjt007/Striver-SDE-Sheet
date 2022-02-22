//Recover Binary Search Tree
//https://leetcode.com/problems/recover-binary-search-tree/

/* //T.C->O(N*log(N)+2*N) && S.C->O(N)
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    void Inorder(TreeNode *root, vector<int> &v, int &i)
    {
        if (root == NULL)
            return;
        Inorder(root->left, v, i);
        if (root->val != v[i])
            root->val = v[i++];
        else
            i++;
        Inorder(root->right, v, i);
    }
    void recoverTree(TreeNode *root)
    {
        if (root == NULL)
            return;
        vector<int> v;
        inorder(root, v);
        sort(v.begin(), v.end());
        int i = 0;
        Inorder(root, v, i);
    }
}; */

//Method2: Using Pointers
//T.C->O(N) && S.C->O(1) excluding Auxilary Space
class Solution
{
public:
    TreeNode *first;
    TreeNode *mid;
    TreeNode *last;
    TreeNode *prev;

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        if (prev != NULL && (root->val < prev->val))
        {
            if (first == NULL)
            {
                first = prev;
                mid = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        first = mid = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && mid)
            swap(first->val, mid->val);
    }
};