//K-th element of two sorted Arrays
//https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
#include<bits/stdc++.h>
using namespace std;

//Method: Using Binary Search
//T.C->O(log(min(N1,N2))) && S.C->O(1)
int kthElement(vector<int>v1, vector<int>v2, int n1, int n2, int k)
{
    if(n1>n2) return kthElement(v2,v1,n2,n1,k);
    int low = max(0,k-n2), high = min(n1,k); //handling all the edge cases
    while (low<=high)
    {
        int cut1 = (low+high)>>1;
        int cut2 = k-cut1;

        int l1 = cut1==0?INT_MIN:v1[cut1-1];
        int l2 = cut2==0?INT_MIN:v2[cut2-1];
        int r1 = cut1==n1?INT_MAX:v1[cut1];
        int r2 = cut2==n2?INT_MAX:v2[cut1];

        if(l1<=r2 && l2<=r1)
        {
            return max(l1,l2);
        }
        else if(l1>r2)
        {
            high = cut1-1;
        }
        else
        {
            low = cut1+1;
        }
    }
    return 1;
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> v2[i];
    }
    int k;
    cin>>k;
    int ans = kthElement(v1, v2, n1,n2,k);
    cout << ans << endl;
}