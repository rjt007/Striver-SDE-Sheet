//Subset-ii Dupicates not allowed
//https://leetcode.com/problems/subsets-ii/
#include <bits/stdc++.h>
using namespace std;

/* //Method: Using Recursion + HashSet
//T.C->O(2^N) && S.C->O(2^N)
void solve(vector<int> nums, vector<int> v, set<vector<int>> &st)
{
    if (nums.size() == 0)
    {
        sort(v.begin(), v.end());
        st.insert(v);
        return;
    }
    vector<int> v1 = v;
    vector<int> v2 = v;
    v1.push_back(nums[0]);
    nums.erase(nums.begin() + 0);
    solve(nums, v1, st);
    solve(nums, v2, st);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<vector<int>> st;
    vector<vector<int>> ans;
    vector<int> v;
    solve(nums, v, st);
    for (auto x : st)
    {
        ans.push_back(x);
    }
    return ans;
} */

//Method: Using Recursion
//T.C->O(2^N * N) && S.C->(O(2^N))
void solve(int idx, vector<int> &nums, vector<int> temp, vector<vector<int>> &ans)
{
    ans.push_back(temp);
    for (int i = idx; i < nums.size(); i++)
    {
        if (i != idx && nums[i] == nums[i - 1])
        {
            continue;
        }
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    solve(0, nums, temp, ans);
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
    vector<vector<int>>ans = subsetsWithDup(v);
    for(auto x:ans)
    {
        for (int i = 0; i < x.size(); i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}