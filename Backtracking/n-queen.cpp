// N-Queens
//https://leetcode.com/problems/n-queens/
#include<bits/stdc++.h>
using namespace std;

/* //Method1: Backtracking
//T.C->O(Exponential)+O(3*N) && S.C->O(N)
bool isvalid(int row, int col, int n, vector<string> &temp)
{
    int currrow = row;
    int currcol = col;
    while (row >= 0 && col >= 0)
    {
        if (temp[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = currrow;
    col = currcol;
    while (col >= 0)
    {
        if (temp[row][col] == 'Q')
            return false;
        col--;
    }
    row = currrow;
    col = currcol;
    while (row < n && col >= 0)
    {
        if (temp[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col, int n, vector<string> &temp, vector<vector<string>> &ans)
{
    if (col == n)
    {
        ans.push_back(temp);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isvalid(row, col, n, temp))
        {
            temp[row][col] = 'Q';
            solve(col + 1, n, temp, ans);
            temp[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    string s(n, '.');
    vector<string> temp(n, s);
    vector<vector<string>> ans;
    solve(0, n, temp, ans);
    return ans;
} */

//Method2: Backtracking with optimisation over Time Complexity
//T.C->O(Exponential) && S.C->O(3*N)
void solve(int col, int n, vector<int> &leftrow, vector<int> &lowerdiagonal, vector<int> &upperdiagonal,
           vector<string> &temp, vector<vector<string>> &ans)
{
    if (col == n)
    {
        ans.push_back(temp);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && lowerdiagonal[row + col] == 0 && upperdiagonal[(n - 1) + col - row] == 0)
        {
            temp[row][col] = 'Q';
            leftrow[row] = 1;
            lowerdiagonal[row + col] = 1;
            upperdiagonal[(n - 1) + col - row] = 1;
            solve(col + 1, n, leftrow, lowerdiagonal, upperdiagonal, temp, ans);
            temp[row][col] = '.';
            leftrow[row] = 0;
            lowerdiagonal[row + col] = 0;
            upperdiagonal[(n - 1) + col - row] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    string s(n, '.');
    vector<string> temp(n, s);
    vector<vector<string>> ans;
    vector<int> leftrow(n, 0), lowerdiagonal(2 * n - 1), upperdiagonal(2 * n - 1);
    solve(0, n, leftrow, lowerdiagonal, upperdiagonal, temp, ans);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<string>>ans = solveNQueens(n);
}