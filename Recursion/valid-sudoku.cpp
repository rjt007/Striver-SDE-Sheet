//Valid Sudoku
//https://leetcode.com/problems/valid-sudoku/
#include<bits/stdc++.h>
using namespace std;

//Method: Recursion + Maths
//T.C->O(N^2) && S.C->O(1), Auxilary Space->O(N)

bool isvalid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if ((3 * (row / 3) + i / 3) == row && (3 * (col / 3) + i % 3) == col)
            continue;
        if (i != row && board[i][col] == c)
            return false;
        if (i != col && board[row][i] == c)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            char c = board[row][col];
            if (c == '.')
                continue;
            else if (!isvalid(board, row, col, c))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    return 0;
}