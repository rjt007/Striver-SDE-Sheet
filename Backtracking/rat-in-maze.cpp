//Rat In A Maze
//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
#include<bits/stdc++.h>
using namespace std;

/* //Method1: Backtracking
//T.C->O(4^(N*M)) && S.C->O(N*M), Auxilary Space->O(N*M)

void solve(int row, int col, int n, string s, vector<string>&ans, vector<vector<int>>&m,vector<vector<int>>&mark)
{
    if(row==n-1 && col==n-1)
    {
        ans.push_back(s);
        return;
    }
    //Down
    if(row+1<n && mark[row+1][col]!=1 && m[row+1][col]!=0)
    {

        mark[row][col]=1;
        solve(row+1,col,n,s+'D',ans,m,mark);
        mark[row][col]=0;
    }
    //Left
    if(col-1>=0 && mark[row][col-1]!=1 && m[row][col-1]!=0)
    {
        mark[row][col]=1;
        solve(row,col-1,n,s+'L',ans,m,mark);
        mark[row][col]=0;
    }
    //Right
    if(col+1<n && mark[row][col+1]!=1 && m[row][col+1]!=0)
    {
        mark[row][col]=1;
        solve(row,col+1,n,s+'R',ans,m,mark);
        mark[row][col]=0;
    }
    //Up
    if(row-1>=0 && mark[row-1][col]!=1 && m[row-1][col]!=0)
    {
        mark[row][col]=1;
        solve(row-1,col,n,s+'U',ans,m,mark);
        mark[row][col]=0;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> ans;
    string s = "";
    vector<vector<int>> mark(n,vector<int>(n,0));
    solve(0, 0, n, s, ans, m, mark);
    return ans;
} */

//Method2: Backtracking[Optimisation in 4 direction paths]
//T.C->O(4^(N*M)) && S.C->O(N*M), Auxilary Space->O(N*M)

void solve(int row, int col, int n, string s, vector<string> &ans, vector<vector<int>> &m, vector<vector<int>> &mark,
vector<int>dir1, vector<int>dir2)
{
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(s);
        return;
    }
    string dir = "DLRU";
    for (int i = 0; i < 4; i++)
    {
        int nextrow = row+dir1[i];
        int nextcol = col+dir2[i];
        if(nextrow>=0 && nextcol>=0 && nextrow<n && nextcol<n && m[nextrow][nextcol]!=0 && mark[nextrow][nextcol]!=1)
        {
            mark[row][col]=1;
            solve(nextrow,nextcol,n,s+dir[i],ans,m,mark,dir1,dir2);
            mark[row][col]=0;
        }
    } 
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> ans;
    string s = "";
    vector<vector<int>> mark(n, vector<int>(n, 0));
    vector<int>dir1 ={1,0,0,-1};
    vector<int>dir2 ={0,-1,1,0};
    if(m[0][0]==1) solve(0, 0, n, s, ans, m, mark, dir1,dir2);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v;
    int temp;
    for (int i = 0; i < n; i++)
    {
        vector<int>val;
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            val.push_back(temp);
        }
        v.push_back(val);
    }
    vector<string>ans = findPath(v,n);
    for (auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}