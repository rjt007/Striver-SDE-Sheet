#include<bits/stdc++.h>
using namespace std;


//Method1: Using Sorting
//T.C->O(n*log(n)) & S.C->O(1)
bool isAnagram(string s, string t)
{
    int n = s.length(), m = t.length();
    if (n != m)
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
            return false;
    }
    return true;
}

//Method2: Using Map
//T.C->O(N) && S.C->O(N)
//Handle any Unicode character as well.
bool isAnagram(string s, string t)
{
    unordered_map<char, int> mp;
    for (char x : s)
    {
        mp[x]++;
    }
    for (char x : t)
    {
        if (mp.find(x) == mp.end())
            return false;
        else
        {
            mp[x]--;
        }
    }
    for (auto x : mp)
    {
        if (x.second != 0)
            return false;
    }
    return true;
}

int main()
{
    string s,t;
    cin>>s>>t;
    bool ans = isAnagram(s,t);
    cout<<ans<<endl;
    return 0;
}