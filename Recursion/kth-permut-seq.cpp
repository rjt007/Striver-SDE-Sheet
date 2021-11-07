//Permutation Sequence
//https://leetcode.com/problems/permutation-sequence/
#include<bits/stdc++.h>
using namespace std;

//Method: Mathematics
//T.C->O(N^2) & S.C->O(N)
string getPermutation(int n, int k)
{
    int fact = 1;
    vector<int> temp;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        temp.push_back(i);
    }
    temp.push_back(n);
    string ans = "";
    k = k - 1; //for indexing purpose
    while (true)
    {
        ans += to_string(temp[k / fact]);
        temp.erase(temp.begin() + k / fact);
        if (temp.empty())
        {
            break;
        }
        k %= fact;
        fact /= temp.size();
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k; 
    string ans = getPermutation(n,k);
    cout<<ans<<endl;
}