//Count and Say
//https://leetcode.com/problems/count-and-say/
#include<bits/stdc++.h>
using namespace std;

//Method1: Iterative
//T.C->O(N*l), l is length of string in each iteration.
//S.C->O(N)
string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string ans = "1";
    for (int i = 2; i <= n; i++)
    {
        ans += '&'; //to run the inner for loop.
        string temp = "";
        int cnt = 1;
        for (int j = 1; j < ans.length(); j++)
        {
            if (ans[j] == ans[j - 1])
                cnt++;
            else
            {
                temp = temp + to_string(cnt);
                temp = temp + ans[j - 1];
                cnt = 1;
            }
        }
        ans = temp;
    }
    return ans;
}

//Method2: Recursive
//T.C->O(N*l), l is length of string in each iteration.
//S.C->O(N), Auxilary space->O(N)
string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string ans = countAndSay(n - 1);

    int cnt = 1;
    string temp = "";
    for (int i = 0; i < ans.length(); i++)
    {
        if (i<ans.length() && ans[i] == ans[i + 1])
            cnt++;
        else
        {
            temp = temp + to_string(cnt);
            temp = temp + ans[i];
            cnt = 1;
        }
    }
    return temp;
}

int main()
{
    int n;
    cin>>n;
    string ans = countAndSay(n);
    cout<<ans<<endl;
    return 0;
}