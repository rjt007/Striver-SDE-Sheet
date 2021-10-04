//Set Matrix Zeroes
//https://leetcode.com/problems/set-matrix-zeroes/
#include<bits/stdc++.h>
using namespace std;

/* //Method1: Brute Force
//T.C->O(N*M*(N+M)) & S.C->O(1)

void solve(vector<vector<int>>&v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(v[i][j]==0)
            {
                for (int k = 0; k < n; k++) //Modifying Row
                {
                    if (v[k][j] != 0)
                    {
                        v[k][j] = -1;
                    }
                }
                for (int k = 0; k < n; k++)//Modifying Column
                {
                    if (v[i][k] != 0)
                    {
                        v[i][k] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(v[i][j]==-1)
            {
                v[i][j]=0;
            }
        }
    }
}
 */

/* //Method2: Using two dummy arrays
//T.C->O(N*M) & S.C->O(N+M)

void solve(vector<vector<int>>&v, int n)
{
    vector<int>row(n,-1);
    vector<int>column(n,-1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(v[i][j]==0)
            {
                row[i]=0;
                column[j]=0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(row[i]==0 || column[j]==0)
            {
                v[i][j]=0;
            }
        }
    }
}
 */

//Method3: Optimised version of method2
//T.C->O(N*M), S.C->O(1)

void solve(vector<vector<int>> &v, int n)
{
    int col = 1;
    for (int i = 0; i < n; i++)
    {
        if(v[i][0]==0)
        {
            col=0;
        }
        for (int j = 1; j < n; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = v[0][j] = 0;
            }
        }
    }

    for (int i = n-1; i>=0; i--)
    {
        for (int j = n-1; j>=1; j--)
        {
            if(v[i][0]==0 || v[0][j]==0)
            {
                v[i][j] = 0;
            }
        }
        if(col==0)
        {
            v[i][0]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n; //here I assumed no of rows = no of columns. (n=m)
    vector<vector<int>>v;
    
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n);
        for (int j = 0; j<n; j++)
        {
            cin>>temp[j];
        }
        v.push_back(temp);
    }
    solve(v,n);
    cout<<"*-------------------------------------*"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}