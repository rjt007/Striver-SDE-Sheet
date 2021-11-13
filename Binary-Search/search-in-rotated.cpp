//Search in Rotated Sorted Array
//https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <bits/stdc++.h>
using namespace std;

//Method: Binary Search 
//T.C->O(log(N)) && S.C->O(1)
int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] >= nums[low])
        {
            if (nums[low] <= target && nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (nums[mid] <= target && nums[high] >= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
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
    int ans = search(v,target);
    cout << ans << endl;
    return 0;
}