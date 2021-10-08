//Unique Grid Path
//https://leetcode.com/problems/unique-paths/
#include<bits/stdc++.h>
using namespace std;

/* //Method1: Using Recurison
//T.C->O(2^N) & S.C->O(2^N), Exponential Complexities
int countPaths(int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (i >= n || j >= m)
    {
        return 0;
    }
    return countPaths(i, j + 1, n, m) + countPaths(i + 1, j, n, m);
}
int uniquePaths(int m, int n)
{
    return countPaths(0, 0, n, m);
} */

/* //Method2: Using Dynamic Programming
//T.C->O(N*M) & S.C->O(N*M)
int dp[101][101];
int countPaths(int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    return dp[i][j] = countPaths(i, j + 1, n, m) + countPaths(i + 1, j, n, m);
}
int uniquePaths(int m, int n)
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            dp[i][j] = -1;
        }
    }
    return countPaths(0, 0, m, n);
} */

//Method3: Using Combinatorics
//T.C->O(N) or O(M) & S.C->O(1)
int uniquePaths(int m, int n)
{
    int directions = m + n - 2;
    int right_dir = n - 1;
    double ans = 1;
    for (int i = 1; i <= right_dir; i++)
    {
        ans = (ans * (directions - right_dir + i)) / i;
    }
    return (int)ans;
}
int main()
{
    int n,m;
    cin>>m>>n;
    //m: rows
    //n:columns
    int uniquepaths = uniquePaths(m,n);
    cout<<"Total Unique Paths are: "<<uniquepaths<<endl;
    return 0;
}