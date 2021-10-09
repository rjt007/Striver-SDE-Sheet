//Reverse Pairs
//https://leetcode.com/problems/reverse-pairs/
#include<bits/stdc++.h>
using namespace std;

//Method: Modified Merge Sort
//T.C->O(N*log(N)+O(N)+O(N)) ~ O(N*log(N)) && S.C->O(N)
int merge(vector<int>&v,vector<int>&temp,int l, int mid, int r)
{
    //Algorithm For Reverse Pair: T.C->O(N)
    int j=mid+1,cnt=0;
    for (int i = l; i <=mid; i++)
    {
        while (j<=r && v[i]>2ll*v[j])
        {
            j++;
        }
        cnt+=j-(mid+1);
    }//
    
    //Normal Merge Sort Thing
    int i=l,k=l;
    j = mid+1;
    while(i<=mid && j<=r)
    {
        if(v[i]<v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++] = v[i++]; 
    }
    while(j<=r)
    {
        temp[k++] = v[j++]; 
    }
    for (int i = l; i <=r; i++)
    {
        v[i] = temp[i];
    }
    return cnt;
}

int mergesort(vector<int>&v, vector<int>&temp, int l, int r)
{
    int cnt=0;
    if(l<r)
    {
        int mid = (l+r)/2;
        cnt+=mergesort(v,temp,l,mid);
        cnt+=mergesort(v,temp,mid+1,r);

        cnt+=merge(v,temp,l,mid,r);
    }
    return cnt;
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
    vector<int>temp(n);
    int cnt_pairs = mergesort(v,temp,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<< v[i]<<" ";
    }
    cout<<"\nTotal Reverse Pairs Present are: "<<cnt_pairs<<endl;
    return 0;
}