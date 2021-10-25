//Longest Substring Without Repeating Characters
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include<bits/stdc++.h>
using namespace std;

/* //Method1: Using Set
//T.C->O(2*N) && S.C->O(N)
void solve(string s)
{
    int n = s.length();
    unordered_set<char>st;
    int l = 0, r = 0, maxlength=0;
    while (l<n && r<n)
    {
        if(st.find(s[r])==st.end())
        {
            maxlength = max(maxlength,r-l+1);
            st.insert(s[r]);
            r++;
        }
        else{
            st.erase(s[l]);
            l++;
        }
    }
    cout<<maxlength<<" ";
} */

//Method1: Using Map
//T.C->O(N) in one pass && S.C->O(N)
void solve(string s)
{
    int n = s.length();
    unordered_map<char,int>mp;
    int l = 0, r = 0, maxlength=0;
    while (l<n && r<n)
    {
        if(mp.find(s[r])!=mp.end())
        {
            l = max(mp[s[r]]+1,l);
        }
        maxlength = max(maxlength, r - l + 1);
        mp[s[r]] = r;
        r++;
    }
    cout<<maxlength<<" ";
}

int main()
{
    string s="";
    cin>>s;
    solve(s);
    return 0;
}