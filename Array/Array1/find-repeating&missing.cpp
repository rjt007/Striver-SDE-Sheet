//Find the repeating & missing element in an array.
//https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

#include<bits/stdc++.h>
using namespace std;

//T.C->O(N) & S.C-.O(N)
//Using Count Array
void solve(vector<int>v, int n)
{
    vector<int>cnt(n+1,0);
    int repeated = 0, sum=0;
    for (int i = 0; i < n; i++)
    {
        if(cnt[v[i]]==1)
        {
            repeated=v[i];
        }
        cnt[v[i]] = 1;
        sum+=v[i];
    }
    int actual_sum = (n*(n+1))/2;
    int missing = actual_sum-sum+repeated;
    cout<<"Missing No: "<<missing<<" "<<"Repeated No: "<<repeated<<endl;
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