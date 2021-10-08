//Majority Element-i
//https://leetcode.com/problems/majority-element/
#include <bits/stdc++.h>
using namespace std;

/* //Method1: Using Hashmap
//T.C->O(N) & S.C->O(N)

int majorityElement(vector<int>&v)
{
    int n = v.size();
    unordered_map<int,int>m;
    for (int i = 0; i < n; i++)
    {
        m[v[i]]++;
    }
    for (auto x:m)
    {
        if(x.second>n/2)
        {
            return x.first;
        }
    }
    return -1;
} */

//Method2: Moores Voting Algorithm
//T.C->O(N) && S.C->O(1)
int majorityElement(vector<int> &nums)
{

    int n = nums.size();
    int cnt = 0, ele = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            ele = nums[i];
        }
        if (ele == nums[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    return ele;
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
    int majorityelement = majorityElement(v);
    cout << "Majority Element is: " << majorityelement << endl;
    return 0;
}