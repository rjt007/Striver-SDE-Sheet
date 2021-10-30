//Max Consecutive Ones
//https://leetcode.com/problems/max-consecutive-ones/
#include <bits/stdc++.h>
using namespace std;

//Method: Using Iteration
//T.C->O(N) && S.C->O(1)
int findMaxConsecutiveOnes(vector<int> &v)
{
    int n = v.size();
    int curr = 0, maxx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            curr++;
        }
        else
        {
            curr = 0;
        }
        maxx = max(curr, maxx);
    }
    return maxx;
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
    int ans = findMaxConsecutiveOnes(v);
    cout << "length of distinct array is: " << ans << endl;
    return 0;
}