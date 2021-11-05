//Permutations
//https://leetcode.com/problems/permutations/
#include <bits/stdc++.h>
using namespace std;

//Method: Recursion + Backtraking
//T.C->O(N!)  && S.C->O(1), Auxilary S.C->O(N)
void solve(int idx, vector<int> &v, vector<vector<int>> &ans)
{
    if (idx == v.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        swap(v[idx], v[i]);
        solve(idx + 1, v, ans);
        swap(v[idx], v[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    solve(0, nums, ans);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<vector<int>>ans = permute(v);
    for (auto  x: ans)
    {
        for (int i = 0; i < x.size(); i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}