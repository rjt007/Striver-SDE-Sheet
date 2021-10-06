//Rotate Matrix 
//https://leetcode.com/problems/rotate-image/
#include <bits/stdc++.h>
using namespace std;

/* //Method1: Brute Force
//T.C->O(N^2) && S.C->O(N^2)
void solve(vector<vector<int>>v, int n, int m)
{
    int v1[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v1[i][j] = v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = v[i][j];
            v[i][j] = v1[j][i];
            v1[j][i] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin(), v[i].end());
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
} */

//Method2: Optimised Transpose
//T.C->O(N^2) S.C->O(1)
void rotate(vector<vector<int>> &mat)
{
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v;
    for (int i = 0; i <n; i++)
    {
        vector<int> temp;
        for(int j=0;j<m;j++)
        {
            int val;
            cin>>val;
            temp.push_back(val);
        }
        v.push_back(temp);
    }
    //solve(v,n,m);
    rotate(v);
    return 0;
}