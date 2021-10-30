//Trapping Rain Water
//https://leetcode.com/problems/trapping-rain-water/
#include <bits/stdc++.h>
using namespace std;

/* //Method1: Brute Force
//T.C->O(N^2) && S.C->O(1)
int trap(vector<int> &v)
{
    int n = v.size(), trap = 0;
    for (int i = 0; i < n; i++)
    {
        int leftmax = 0, rightmax = 0;
        for (int j = i; j >= 0; j--)
        {
            leftmax = max(leftmax, v[j]);
        }
        for (int j = i; j < n; j++)
        {
            rightmax = max(rightmax, v[j]);
        }
        //cout<<leftmax<<" "<<rightmax<<endl;
        trap += min(leftmax, rightmax) - v[i];
    }
    return trap;
} */

/* //Method2: Using Prefix & Suffix Sum Array
//T.C->O(N) && S.C->O(N)

int trap(vector<int> &v)
{
    int n = v.size();
    int mx = 0, mx1 = 0, trap = 0;
    vector<int> prefix(n);
    vector<int> suffix(n);
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, v[i]);
        prefix[i] = mx;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        mx1 = max(mx1, v[i]);
        suffix[i] = mx1;
    }
    for (int i = 0; i < n; i++)
    {
        trap += min(prefix[i], suffix[i]) - v[i];
    }
    return trap;
}
 */
//Method3: Using 2-Pointers
//T.C->O(N) & S.C->O(1)
int trap(vector<int> &v)
{
    int n = v.size();
    int l = 0, r = n - 1, leftmax = 0, rightmax = 0, trap = 0;
    while (l < r)
    {
        if (v[l] <= v[r])
        {
            if (v[l] >= leftmax)
            {
                leftmax = v[l];
            }
            else
            {
                trap += leftmax - v[l];
            }
            l++;
        }
        else
        {
            if (v[r] >= rightmax)
            {
                rightmax = v[r];
            }
            else
            {
                trap += rightmax - v[r];
            }
            r--;
        }
    }
    return trap;
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
    int ans = trap(v);
    cout << "amount of water trapped is: " << ans << endl;
    return 0;
}