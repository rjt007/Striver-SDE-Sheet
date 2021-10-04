//Pascals Triangle
//https://leetcode.com/problems/pascals-triangle/
#include <bits/stdc++.h>
using namespace std;

//T.C->O(N^2) & S.C->O(N^2)
vector<vector<int>> generate(int n)
{
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++)
    {
        v[i].resize(i + 1);
        v[i][0] = v[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }
    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>>ans = generate(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}