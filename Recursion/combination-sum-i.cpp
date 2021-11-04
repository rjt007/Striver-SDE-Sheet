//Combination Sum
//https://leetcode.com/problems/combination-sum/
#include<bits/stdc++.h>
using namespace std;

/* //Method: Recursion (My Solution)
//T.C->O(2^t * k) && S.C->O(k)
void solve(vector<int> &v, vector<int> temp, vector<vector<int>> &ans, int idx, int target)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (target < 0 || idx >= v.size())
    {
        return;
    }
    vector<int> temp1 = temp;
    vector<int> temp2 = temp;
    temp1.push_back(v[idx]);
    solve(v, temp1, ans, idx, target - v[idx]);
    solve(v, temp2, ans, idx + 1, target);
}
vector<vector<int>> combinationSum(vector<int> &v, int target)
{
    vector<int> temp;
    vector<vector<int>> ans;
    solve(v, temp, ans, 0, target);
    return ans;
} */

//Method: Recursion + Backtraking
//T.C->O(2^t * k) && S.C->O(k)
void solve(int idx, int target, vector<int> &v, vector<vector<int>> &ans, vector<int> &temp)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (target != 0 && idx >= v.size())
    {
        return;
    }
    // pick up the element
    if (v[idx] <= target)
    {
        temp.push_back(v[idx]);
        solve(idx, target - v[idx], v, ans, temp);
        temp.pop_back();
    }
    //not picking & moving to next index
    solve(idx + 1, target, v, ans, temp);
}

vector<vector<int>> combinationSum(vector<int> &v, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, target, v, ans, temp);
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
    cin>>target;
    vector<vector<int>> ans = combinationSum(v,target);
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