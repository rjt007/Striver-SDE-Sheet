//Two Sum
//https://leetcode.com/problems/two-sum/
#include<bits/stdc++.h>
using namespace std;

//Method: Using Unordered_map
//T.C->O(N) && S.C->O(N)
//T.C-> [O(N^2) in worst case, which is probably not happens in this problem]
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> v;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(target - nums[i]) != m.end())
        {
            v.push_back(i);
            v.push_back(m[target - nums[i]]);
            break;
        }
        m[nums[i]] = i;
    }
    return v;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i <n; i++)
    {
        cin>>v[i];
    }
    int target;
    cin>>target;
    vector<int>ans = twoSum(v,target);
    cout<<"Indices are: "<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}