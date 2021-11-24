//Compare Version Numbers
//https://leetcode.com/problems/compare-version-numbers/
#include<bits/stdc++.h>
using namespace std;

//Method: Using 2-Pointers + Implementation
//T.C->O(N+M) && S.C->O(1)
int compareVersion(string v1, string v2)
{
    int n = v1.length(), m = v2.length();
    int digit1 = 0, digit2 = 0;
    int i = 0, j = 0;
    while (i < n || j < m)
    {
        while (i < n && v1[i] != '.')
        {
            digit1 = digit1 * 10 + (v1[i] - '0');
            i++;
        }
        while (j < m && v2[j] != '.')
        {
            digit2 = digit2 * 10 + (v2[j] - '0');
            j++;
        }
        if (digit1 > digit2)
            return 1;
        else if (digit2 > digit1)
            return -1;
        digit1 = 0;
        digit2 = 0;
        i++;
        j++;
    }
    return 0;
}

int main()
{
    string v1,v2;
    cin>>v1>>v2;
    int ans = compareVersion(v1,v2);
    cout<<ans<<endl;
    return 0;
}