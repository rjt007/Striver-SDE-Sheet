//Next Permutation
//https://leetcode.com/problems/next-permutation/
#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>&v,int n)
{
    int idx1=0,idx2=0;
    for (int i = n-2; i>=0; i--)
    {
        if(v[i]<v[i+1])
        {
            idx1 = i;
            break;
        }
    }
    for (int i = n-1; i>=0; i--)
    {
        if(v[i]>v[idx1])
        {
            idx2 = i;
            break;
        }
    }
    swap(v[idx1],v[idx2]);
    if(idx1==0 && idx2==0)
    {
        reverse(v.begin(),v.end());
    }
    else
    {
        reverse(v.begin() + idx1 + 1, v.end());
    }

    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
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
    solve(v,n);
    return 0;
}