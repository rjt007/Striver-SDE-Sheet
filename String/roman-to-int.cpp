//Roman to Integer
//https://leetcode.com/problems/roman-to-integer/
#include <bits/stdc++.h>
using namespace std;

//Using Map and Iteration
//T.C->O(N) && S.C->O(1)
int romanToInt(string s)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int ans = mp[s[0]];
    for (int i = 1; i < s.length(); i++)
    {
        if (mp[s[i - 1]] >= mp[s[i]])
        {
            ans += mp[s[i]];
        }
        else
        {
            //ans-=mp[s[i-1]];
            ans += mp[s[i]] - 2 * mp[s[i - 1]];
        }
    }
    return ans;
}

int main()
{
    string s = "";
    cin>>s;
    int ans = romanToInt(s);
    cout << ans << endl;
    return 0;
}