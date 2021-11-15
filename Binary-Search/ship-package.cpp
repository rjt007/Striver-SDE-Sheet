//Capacity To Ship Packages Within D Days
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#include <bits/stdc++.h>
using namespace std;

//Method: Binary Search
//T.C->O(N*log(N)) && S.C->O(1)
bool isvalid(vector<int> &v, int days, int minweight)
{
    int n = v.size(), weight = 0, day = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > minweight)
            return false;
        if (weight + v[i] > minweight)
        {
            day++;
            weight = v[i];
        }
        else
        {
            weight += v[i];
        }
        if (day > days)
            return false;
    }
    return true;
}

int shipWithinDays(vector<int> &v, int days)
{
    int n = v.size();
    int low = 1, high = accumulate(v.begin(), v.end(), 0), minweight = 0;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isvalid(v, days, mid))
        {
            minweight = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return minweight;
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
    int days;
    cin >> days;
    int ans = shipWithinDays(v, days);
    cout << ans << endl;
    return 0;
}