//Remove Duplicates from Sorted Array
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <bits/stdc++.h>
using namespace std;

//Method: Using 2-Pointer
//T.C->O(N) && S.C->O(1)
int removeDuplicates(vector<int> &v)
{
    int n = v.size();
    if (n == 0 || n == 1)
    {
        return n;
    }
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        if (v[i] != v[j])
        {
            i++;
            v[i] = v[j];
        }
        j++;
    }
    return i + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = removeDuplicates(v);
    cout<<"length of distinct array is: "<<ans<<endl;
    return 0;
}