//Combination Sum-ii
//https://leetcode.com/problems/combination-sum-ii/
#include <bits/stdc++.h>
using namespace std;

//Method: Recursion + Backtraking
//T.C->O(2^N) && S.C->O(N)
void solve(int idx, int target, vector<int> &v, vector<vector<int>> &ans, vector<int> temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        if (i > idx && v[i] == v[i - 1])
        {
            continue;
        }
        if (v[i] > target)
        {
            break;
        }
        temp.push_back(v[i]);
        solve(i + 1, target - v[i], v, ans, temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    vector<vector<int>> ans;
    solve(0, target, candidates, ans, temp);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int target;
    cin >> target;
    vector<vector<int>> ans = combinationSum2(v, target);
    for (auto x : ans)
    {
        for (int i = 0; i < x.size(); i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}