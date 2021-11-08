#include<bits/stdc++.h>
using namespace std;

void solve(int row, int col, int n, string s, vector<string>)

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> ans;
    string s = "";
    vector<vector<int>> mark(n,vector<int>(n,0));
    solve(0, 0, n, s, ans, m, mark);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<string>ans = findPath(v,n);
    return 0;
}