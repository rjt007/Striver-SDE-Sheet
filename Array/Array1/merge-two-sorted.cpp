//Merge Two Sorted Array
//https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/

#include<bits/stdc++.h>
using namespace std;

/* //Method1: Using Extra Space.
//T.C->O(N+M) && S.C->O(N+M), extra space. 
void solve(vector<int>v1, vector<int>v2,int n, int m)
{
    vector<int>v;
    int i=0,j=0;
    while (i<n && j<m)
    {
        if(v1[i]<v2[j])
        {
            v.push_back(v1[i]);
            i++;
        }
        else if(v1[i]==v2[j])
        {
            v.push_back(v1[i]);
            v.push_back(v2[j]);
            i++;
            j++;
        }
        else
        {
            v.push_back(v2[j]);
            j++;
        }
    }
    while (i<n)
    {
        v.push_back(v1[i]);
        i++;
    }
    while (j<m)
    {
        v.push_back(v2[j]);
        j++;
    }
    
    for (int k = 0; k < v.size(); k++)
    {
        cout<<v[k]<<" ";
    }
    cout<<endl;
} */

//Method2: Using Insertion Sort, without extra space
//T.C->O(N*M) & S.C->O(1)
void sort_v2(vector<int>&v2,int m)
{
    for(int i=0;i<m-1;i++)
    {
        if(v2[i]>v2[i+1])
        {
            swap(v2[i],v2[i+1]);
        }
    }
}
void solve(vector<int> &v1, vector<int> &v2, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        if(v1[i]>v2[0])
        {
            swap(v1[i],v2[0]);
            sort_v2(v2,m);
        }
    }
}

//Method3: Gap Method
//T.C->O(N*LOG(M+N)) & S.C->O(1)
void solve(vector<int> &v1, vector<int> &v2, int n, int m)
{
    int gap = ceil((n+m)/2);
    int i=0, j=gap-1;
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v1(n);
    vector<int>v2(m);
    for (int i = 0; i < n; i++)
    {
        cin>>v1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>v2[i];
    } 
    solve(v1,v2,n,m);
    for (int i = 0; i < n; i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < m; i++)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;
    return 0;
}