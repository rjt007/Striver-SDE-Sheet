//Maximum Sum Subarray: Kaden's Algorithm
//https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h>
using namespace std;

/* //Method1: Brute Force
//T.C->O(N*2) & S.C->O(1)
int solve(vector<int>v, int n)
{
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int temp = v[i];
        maxsum = max(v[i],maxsum);
        for (int j = i+1; j < n; j++)
        {
            temp+=v[j];
            maxsum = max(maxsum,temp);
        }
    }
    return maxsum;
} */

//Method2: Kaden's Algorithm
//T.C->O(N) & S.C->O(1)
int solve(vector<int>v, int n)
{
    int currsum=0;
    int maxsum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum+=v[i];
        maxsum = max(maxsum, currsum);
        if(currsum<0)
        {
            currsum=0;
        }
    }
    return maxsum;
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
    int maxsum = solve(v,n);
    cout<<"Maximum Sum is: "<<maxsum<<endl;
    return 0;
}