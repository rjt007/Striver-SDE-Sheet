//Sort an array {0,1,2} without using any sorting algo.
//https://leetcode.com/problems/sort-colors/
#include<bits/stdc++.h>
using namespace std;

//T.C->O(N), S.C->O(1)
//DNF SORT ALGO IS USED
void solve(vector<int>&v, int n)
{
    int low = 0, mid = 0, high = n-1;
    while(mid<=high)
    {
        if(v[mid]==0)
        {
            swap(v[mid],v[low]);
            low++;
        }
        else if(v[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(v[high], v[mid]);
            high--;
        }
    }
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
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}