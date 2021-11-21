//Longest Common Prefix
//https://leetcode.com/problems/longest-common-prefix/
#include <bits/stdc++.h>
using namespace std;

//Method1: Using 2-Pointers 
//T.C->O(n*m) or O(sum of all string of each element of vector)
//S.C->O(1), not considering answer string to be returned

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
        return "";
    int n = strs.size();
    string ans = strs[0];
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        string temp = "";
        while (j < min(strs[i].length(), ans.length()) && strs[i][j] == ans[j])
        {
            temp += ans[j];
            j++;
        }
        ans = temp;
    }
    return ans;
}

/* //Method2: Using Binary Search
//T.C->O(log(m)*(N*M)) && S.C->O(1)
bool lcp(vector<string> &strs, int mid)
{
    string s = strs[0].substr(0, mid);
    for (int i = 1; i < strs.size(); i++)
    {
        if (strs[i].substr(0, mid) != s)
            return false;
    }
    return true;
}
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 1)
        return strs[0];
    int n = strs.size();
    int low = 0, high = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (high > strs[i].length())
            high = strs[i].length();
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (lcp(strs, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return strs[0].substr(0, (low + high) / 2);
} */

int main()
{
    int n;
    cin>>n;
    vector<string>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    string ans = longestCommonPrefix(v);
    return 0;
}