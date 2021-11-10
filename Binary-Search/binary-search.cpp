#include<bits/stdc++.h>
using namespace std;

bool binarysearch(vector<int>&v, int low, int high,int target)
{
    while (low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]==target) return true;
        else if(v[mid]<target)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return false;
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
    int target;
    cin>>target;
    sort(v.begin(),v.end());
    bool ans = binarysearch(v,0,n-1,target);
    if(ans) cout<<"Element Found!!\n";
    else cout<<"Element Not Found!!\n";
    return 0;
}