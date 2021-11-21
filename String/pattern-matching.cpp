//Implement strStr()
//https://leetcode.com/problems/implement-strstr/
#include<bits/stdc++.h>
using namespace std;

/* //Method1: Using 2-Pointers
//T.C->O(N*M) & S.C->O(1)
int strStr(string haystack, string needle)
{
    if (needle.empty())
        return 0;
    int n = haystack.length();
    int m = needle.length();
    for (int i = 0; i < n; i++)
    {
        int j = i, temp = m, idx = 0;
        while (temp--)
        {
            if (haystack[j] != needle[idx])
                break;
            j++;
            idx++;
        }
        if (temp < 0)
            return i;
    }
    return -1;
}
 */

/* //Method2: Using Rabin Karp Algorithm
//T.C->O(N+M) in Average Case & O(N*M) in Worst Case
//S.C->O(1)
int strStr(string haystack, string needle)
{
    int n = haystack.length(), m = needle.length();
    int d = 256, q = 919;
    int p = 0, t = 0, h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    for (int i = 0; i < m; i++)
    {
        p = (p * d + needle[i]) % q;
        t = (t * d + haystack[i]) % q;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        if (i < n - m)
        {
            t = (d * (t - haystack[i] * h) + haystack[i + m]) % q;
            if (t < 0)
            {
                t += q;
            }
        }
    }
    return -1;
}
 */

//Method2: Using KMP Algorithm
//T.C->O(N+M) & S.C->O(N)

vector<int> prefixarray(string s)
{
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int strStr(string haystack, string needle)
{
    if (needle.empty())
        return 0;
    int n = haystack.size(), m = needle.size();
    vector<int> pi = prefixarray(needle);
    int i = 0, j = 0;
    while (i < n)
    {
        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = pi[j - 1];
            else
                i++;
        }
        if (j == m)
        {
            return i - m;
        }
    }
    return -1;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int ans = strStr(s1,s2);
    cout<<16705%919<<endl;
    cout<<"Pattern found at index "<<ans<<endl;
    return 0;
}