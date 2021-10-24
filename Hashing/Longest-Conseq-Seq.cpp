//Longest Consecutive Element Sequence
//https://leetcode.com/problems/longest-consecutive-sequence/
#include<bits/stdc++.h>
using namespace std;

/* //Method1: Using Sorting
//T.C->O(N*log(N)) && S.C->O(1)
int longestConsecutive(vector<int> &v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    int maxlength = 1, currlength = 1;
    if (v.size() == 0 || v.size() == 1)
    {
        return v.size();
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] != v[i])
        {
            if (v[i + 1] == v[i] + 1)
            {
                currlength++;
            }
            else
            {
                currlength = 1;
            }
        }
        maxlength = max(currlength, maxlength);
    }
    return maxlength;
} */

//Method2: Using Set
//T.C->O(N) & S.C->O(N) or O(1)

int longestConsecutive(vector<int> &v)
{
    int n = v.size();
    int maxlength = 0;
    unordered_set<int>s;
    for (int i = 0; i < n; i++)
    {
        s.insert(v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if(s.find(v[i]-1)==s.end())
        {
            int num = v[i];
            int currlength = 1;

            while (s.find(num+1)!=s.end())
            {
                num++;
                currlength++;
            }
            maxlength = max(maxlength,currlength);
        }
    }
    return maxlength;
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
    int ans = longestConsecutive(v);
    cout<<"LCS IS: "<<ans<<endl;
    return 0;
}