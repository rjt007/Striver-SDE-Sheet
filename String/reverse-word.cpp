//Reverse Words in a String
//https://leetcode.com/problems/reverse-words-in-a-string/
#include<bits/stdc++.h>
using namespace std;


/* //Method1: Using Vector & Stringstream
//T.C->O(N) & S.C->O(N)
string reverseWords(string s)
{
    vector<string> v;
    stringstream ss(s);
    string ans = "";
    while (ss >> ans)
    {
        v.push_back(ans);
    }
    ans = "";
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == " ")
        {
            continue;
        }
        ans += v[i] + " ";
    }
    ans.pop_back();
    return ans;
} */

//Method1: Using 2-Pointers
//T.C->O(N) & S.C->O(1)
string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    int n = s.length(), index = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            if (index != 0)
                s[index++] = ' ';
            int j = i;
            while (j < n && s[j] != ' ')
            {
                s[index++] = s[j++];
            }
            reverse(s.begin() + index - (j - i), s.begin() + index);
            i = j;
        }
    }
    s.resize(index);
    //s.erase(s.begin()+index, s.end());
    return s;
}

int main()
{
    string s="";
    getline(cin,s);
    string ans = reverseWords(s);
    cout<<ans<<endl;
    return 0;
}