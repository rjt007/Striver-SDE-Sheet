//Permutations
//https://leetcode.com/problems/permutations/
#include <bits/stdc++.h>
using namespace std;

//Method1: Using Recursion + Freq Array
//T.C->O(N! * N) && S.C->O(2*N),Auxilary S.C->O(N)
void solve(vector<int> &v, vector<int> &temp, vector<int> &freq, vector<vector<int>> &ans)
{
    if (temp.size() == v.size())
    {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (!freq[i])
        {
            temp.push_back(v[i]);
            freq[i] = 1;
            solve(v, temp, freq, ans);
            temp.pop_back();
            freq[i] = 0;
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;
    vector<int> freq(n, 0);
    vector<vector<int>> ans;
    solve(nums, temp, freq, ans);
    return ans;
}

//Method2: Recursion + Backtraking
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