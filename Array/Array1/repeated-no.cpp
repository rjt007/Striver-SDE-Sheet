//https://leetcode.com/problems/find-the-duplicate-number/
#include<bits/stdc++.h>
using namespace std;

//Most Optimised Method: Linked List Cycle Method using Hare-Tortoise or Slow-Fast pointer.
//T.C->O(N) & S.C->O(1)
int solve(vector<int>v)
{
    int fast=v[0], slow=v[0];
    do
    {
        slow = v[slow];
        fast = v[v[fast]];   
    } while (fast!=slow);
    fast = v[0];
    while (fast!=slow)
    {
        slow = v[slow];
        fast = v[fast];
    }
    return slow; //or return fast;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i <n; i++)
    {
        cin>>v[i];
    }
    int repeated = solve(v);
    cout<<"Repeated No. is: "<<repeated<<endl;
    return 0;
}