//Palindrome Partitioning
//https://leetcode.com/problems/palindrome-partitioning/
#include<bits/stdc++.h>
using namespace std;

//Method: Recursion + Backtracking
//T.C->O(2^N *N) && S.C->O(N)
bool ispalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve(string s, int idx, vector<string> temp, vector<vector<string>> &ans)
{
    if (idx == s.length())
    {
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if (ispalindrome(s, idx, i))
        {
            temp.push_back(s.substr(idx, i - idx + 1));
            solve(s, i + 1, temp, ans);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;
    solve(s, 0, temp, ans);
    return ans;
}

int main()
{
    string s="";
    cin>>s;
    vector<vector<string>>ans = partition(s);
    for (auto  x: ans)
    {
        for (int i = 0; i < x.size(); i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}