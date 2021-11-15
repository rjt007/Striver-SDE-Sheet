//Valid Parentheses
//https://leetcode.com/problems/valid-parentheses/
#include<bits/stdc++.h>
using namespace std;

//Method: Using Stack
//T.C->O(N) & S.C->O(N)
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;

            if (s[i] == ')')
            {
                if (st.top() != '(')
                    return false;
            }

            else if (s[i] == '}')
            {
                if (st.top() != '{')
                    return false;
            }

            else if (s[i] == ']')
            {
                if (st.top() != '[')
                    return false;
            }
            st.pop();
        }
    }
    if (st.empty())
        return true;
    return false;
}

int main()
{
    string s ="";
    cin>>s;
    bool val = isValid(s);
    if(val) cout<<"Valid"<<endl;
    else cout<<"Invalid"<<endl;
    return 0;
}