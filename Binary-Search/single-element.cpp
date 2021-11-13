//Single Element in a Sorted Array
//https://leetcode.com/problems/single-element-in-a-sorted-array/
#include<bits/stdc++.h>
using namespace std;

/* //Method1: Using Xor iteration
//T.C->O(N) && S.C->O(1)
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int xorr=0;
    for (int i = 0; i < n; i++)
    {
        xorr^=nums[i];
    }
    return xorr;
} */

//Method2: Using Binary Search
//T.C->O(log(n)) && S.C->O(1)
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid] == nums[mid ^ 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return nums[low];
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
    int ans = singleNonDuplicate(v);
    cout<<ans<<endl;
    return 0;
}