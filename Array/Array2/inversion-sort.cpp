//Count Inversions
//https://www.geeksforgeeks.org/counting-inversions/
#include<bits/stdc++.h>
using namespace std;

//Method1: Using Modified Merge Sort
//T.C->O(N*LOG(N)) && S.C->O(N);
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i=left, j=mid,k=left;
    int inv_cnt=0;
    while (i<=mid-1 && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_cnt= inv_cnt + (mid-i);
        }
    }
    while (i<=mid-1)
    {
        temp[k++] = arr[i++];
    }
    while (j<=right)
    {
        temp[k++] = arr[j++];
    }
    for ( i = left; i <=right; i++)
    {
        arr[i] = temp[i];
    }
    return inv_cnt;
}

int mergesort(int arr[], int temp[], int left, int right)
{
    int mid, inv_cnt = 0;
    if (left<right)
    {
        mid = (left + right) / 2;
        inv_cnt+=mergesort(arr,temp,left,mid);
        inv_cnt+=mergesort(arr,temp,mid+1,right);
        inv_cnt += merge(arr,temp,left,mid+1,right);
    }
    return inv_cnt;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int temp[n];
    int count_inv = mergesort(arr,temp,0,n-1);
    cout<<"Total Inversion Count is: "<<count_inv<<endl;
    return 0;
}