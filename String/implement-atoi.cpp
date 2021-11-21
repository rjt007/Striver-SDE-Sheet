//String to Integer (atoi)
//https://leetcode.com/problems/string-to-integer-atoi/
#include<bits/stdc++.h>
using namespace std;


//Method: Maths & Integer Overflow Knowledge
//T.C->O(N) & S.C->O(1)

int myAtoi(string s)
{
    int i = 0, sign = 1, base = 0;
    while (s[i] == ' ')
        i++;
    if (s[i] == '+' || s[i] == '-')
    {
        sign = 1 - 2 * (s[i] == '-');
        i++;
    }
    while (i < s.length() && s[i] >= '0' && s[i] <= '9')
    {
        //Handling the extreme corner case.
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) 
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        base = 10 * base + (s[i++] - '0');
    }
    return sign * base;
}

int main()
{
    int ans = '8'-'5';
    cout<<ans<<endl;
}