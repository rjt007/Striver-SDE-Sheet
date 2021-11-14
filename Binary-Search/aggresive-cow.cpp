//Aggressive Cows
//https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
using namespace std;

//Method1: Using Binary Search
//T.C->O(N*log(N)) && S,C->O(1)

bool ispossible(vector<int>&v, int cow, int mindistance)
{
    int no_of_cows = 1, n = v.size();
    int distance = v[0];
    for (int i = 1; i < n; i++)
    {
        if(v[i]-distance>=mindistance)
        {
            no_of_cows++;
            distance = v[i];
        }
    }
    if(no_of_cows>=cow)
    {
        return true;
    }
    return false;
}

int aggresivecow(vector<int>&v, int cow)
{
    int n = v.size(), ans=0;
    int low = v[0];
    int high = v[n-1]-low;
    while (low<=high)
    {
        int mid = (low+high)>>1;
        if(ispossible(v,cow,mid))
        {
            ans = max(ans,mid);
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
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
    int cow;
    cin >> cow;
    sort(v.begin(),v.end());
    int ans = aggresivecow(v, cow);
    cout << ans << endl;
    return 0;
}