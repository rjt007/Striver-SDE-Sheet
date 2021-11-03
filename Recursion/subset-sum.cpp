//Subset Sum
//https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include<bits/stdc++.h>
using namespace std;

//Method: Recursion
//T.C->O(2^N) && S.C->O(2^N)
void solve(vector<int>v,int ans,vector<int>&res)
{
    if(v.size()==0)
    {
        res.push_back(ans);
        return;
    }
    int op1 = ans;
    int op2 = ans;
    op1+=v[0];
    v.erase(v.begin()+0);
    solve(v,op1,res);
    solve(v,op2,res);
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
    int ans=0;
    vector<int>res;
    solve(v,ans,res);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}