//Subarray with given Xor
//https://www.interviewbit.com/problems/subarray-with-given-xor/

#include<bits/stdc++.h>
using namespace std;

/* 
//Method1: Brute Force
//T.C->O(N^2) & S.C->O(N)
void solve(vector<int>v, int xorr)
{
    int n = v.size();
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        int currxor = v[i];
        if(currxor==xorr)
        {
            cnt++;
        }
        for (int j =i+1; j < n; j++)
        {
            currxor^=v[j];
            if(currxor==xorr)
            {
                cnt++;
            }
        }
    }
    cout<<cnt<<" ";
} */

//Method2: Using Map
//T.C->O(N) & S.C->O(N)
void solve(vector<int>v, int xr)
{
    int n = v.size();
    int cnt=0,xorr=0;
    unordered_map<int,int>mp;
    for (int i = 0; i < n; i++)
    {
        xorr ^= v[i];
        if(xorr==xr)
        {
            cnt++;
        } 
        if(mp.find(xorr^xr)!=mp.end())
        {
            cnt+=mp[xorr^xr];
        }
        mp[xorr]++;
    }
    cout<<cnt<<" ";
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int xorr;
    cin>>xorr;
    solve(v,xorr);
    return 0;
}