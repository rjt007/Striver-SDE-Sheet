//Largest subarray with 0 sum
//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#
#include <bits/stdc++.h>
using namespace std;

/* //Brute Force:
//T.C->O(N^2) & S.C->O(1)
int maxLen(vector<int>v)
{
    int n = v.size();
    int maxlen=0;
    for (int i = 0; i <n; i++)
    {
        int cnt=0,sum=v[i];
        if (v[i]==0)
        {
            cnt++;
        }
        for (int j = i+1; j < n; j++)
        {
            sum += v[j];
            if(sum==0)
            {
                cnt=max(j-i+1,cnt);
            }
        }
        maxlen = max(cnt,maxlen);
    }
    cout<<maxlen<<endl;
    return 0;
} */
//Method2: Using HashMap
//T.C->O(N) & S.C->O(N)
int maxLen(vector<int>v)
{
    int n = v.size();
    unordered_map<int,int>mp;
    int maxlen=0,sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=v[i];
        if(sum==0)
        {
            maxlen = i+1;
        }
        else
        {
            if(mp.find(sum)!=mp.end())
            {
                maxlen = max(maxlen,i-mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    return maxlen; 
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
    int ans = maxLen(v);
    cout<<"Length of largest subarray with sum 0 is: "<<ans<<endl;
    return 0;
}