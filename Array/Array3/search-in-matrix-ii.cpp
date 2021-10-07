// Search a 2D Matrix II
//https://leetcode.com/problems/search-a-2d-matrix-ii/
#include<bits/stdc++.h>
using namespace std;

//T.C->O(N+M) & S.C->O(1)
bool solve(vector<vector<int>> &v, int target)
{
    int n = v.size();
    int m = v[0].size();
    int i = 0, j = m - 1;
    bool check = false;
    while (i < n && j >= 0)
    {
        if (v[i][j] == target)
        {
            check = true;
            break;
        }
        else if (v[i][j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return check;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        v.push_back(temp);
    }
    int target;
    cin >> target;
    bool ans = solve(v, target);
    if (ans)
    {
        cout << "Element is present!!" << endl;
    }
    else
    {
        cout << "Element is not present!!" << endl;
    }
    return 0;
}