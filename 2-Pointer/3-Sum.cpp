//3-Sum
//https://leetcode.com/problems/3sum/
#include<bits/stdc++.h>
using namespace std;
/* 
//Method1: Using Sorting+ 2-Pointer + Hashing
//T.C->O(N^2*log(N)) && S.C->O(N)
void solve(vector<int> &v)
{
    int n = v.size();
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1, k = n - 1;
        int sum = -1 * v[i];
        while (j < k)
        {
            if (v[j] + v[k] == sum)
            {
                vector<int> temp = {v[i], v[j], v[k]};
                st.insert(temp);
                j++;
                k--;
            }
            else if (v[j] + v[k] < sum)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    for (auto x : st)
    {
        cout<<"{";
        for (int i = 0; i < 3; i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<"}"<<endl;
        //ans.push_back(x);
    }
}
 */

//Method2: Using Sorting + 2-Pointer + Skipping Duplicates
//T.C->O(N^2) && S.C->O(1)
void solve(vector<int> &v)
{
    int n = v.size();
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        int sum = -1 * v[i];
        while (j < k)
        {
            if (v[j] + v[k] == sum)
            {
                vector<int> temp = {v[i], v[j], v[k]};
                ans.push_back(temp);

                while (j < k && v[j] == temp[1])
                {
                    j++;
                }
                while (j < k && v[k] == temp[2])
                {
                    k--;
                }
            }
            else if (v[j] + v[k] < sum)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
        while (i + 1 < n && v[i] == v[i + 1])
        {
            i++;
        }
    }

    for (auto x: ans)
    {
        for(int i=0;i<3;i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    solve(v);
    return 0;
}