//Merge Interval
//https://leetcode.com/problems/merge-intervals/
#include<bits/stdc++.h>
using namespace std;

//T.C->O(N*LOG(N)) & S.C->O(N)
void solve(vector<vector<int>>v, int n)
{
    sort(v.begin(),v.end());
    vector<vector<int>>merge;
    vector<int>temp = v[0];
    for (int i = 0; i < n; i++)
    {
        if(temp[1]>=v[i][0])
        {
            temp[1] = max(temp[1],v[i][1]);
        }
        else
        {
            merge.push_back(temp);
            temp = v[i];
        }
    }
    merge.push_back(temp); //to store the last merged value

    for (int i = 0; i < merge.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << merge[i][j] << " ";
        }
        cout << endl;
    }
} 
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(2);
        cin>>temp[0]>>temp[1];
        v[i] = temp;
    }
    solve(v,n);
    return 0;
}