//Minimum Platforms
//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
#include<bits/stdc++.h>
using namespace std;

//Method: Optimal Greedy & 2-Pointers
//T.C->O(N*log(N)) && S.C->O(1) 
int findPlatform(vector<int>arr, vector<int>dep, int n)
{
    // Your code here
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 1, j = 0, platform_needed = 1, ans = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            platform_needed++;
            i++;
        }
        else
        {
            platform_needed--;
            j++;
        }
        ans = max(ans, platform_needed);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dep(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }
    int ans = findPlatform(arr, dep, n);
    cout << ans << endl;
    return 0;
}