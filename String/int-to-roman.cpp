//Integer to Roman
//https://leetcode.com/problems/integer-to-roman/
#include <bits/stdc++.h>
using namespace std;

//Using Vector and Maths
//T.C->O(N) && S.C->O(1)
string intToRoman(int num)
{
    vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> integerval = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";
    int i = 0;
    while (num)
    {
        while (num >= integerval[i])
        {
            num -= integerval[i];
            ans += roman[i];
        }
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string ans = intToRoman(n);
    cout << ans << endl;
    return 0;
}