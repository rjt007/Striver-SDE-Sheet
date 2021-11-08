//Sudoku Solver
//https://leetcode.com/problems/sudoku-solver/
#include<bits/stdc++.h>
using namespace std;

//Method: Backtracking + Mathematics
//T.C->O(Exponential) & S.C->O(1)
bool isvalid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
        {
            return false;
        }

        if (board[row][i] == c)
        {
            return false;
        }

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isvalid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (solve(board) == true)
                        {
                            return true;
                        }

                        else
                        {
                            board[i][j] = '.'; //backtracking
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{
    return 0;
}