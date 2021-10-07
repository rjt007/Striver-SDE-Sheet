//Search a 2D Matrix
//https://leetcode.com/problems/search-a-2d-matrix/
#include<bits/stdc++.h>
using namespace std;

/* //Method1: Using Binary Search
//T.C->N*LOG(M) & S.C->O(1)

bool solve(vector<vector<int>>v, int target)
{
    int n = v.size();

    bool check = false;

    for (int i = 0; i < n; i++)
    {
        if(binary_search(v[i].begin(),v[i].end(),target))
        {
            check = true;
            break;
        }   
    }
    return check;
} */

/* //Method2: Optimised Binary Search
//T.C->O(N*log(M)) & S.C->O(1)
bool solve(vector<vector<int>> v, int target)
{
    int n = v.size();
    int m = v[0].size();
    bool check = false;

    for (int i = 0; i < n; i++)
    {
        if(target<v[i][0])
        {
            break;
        }
        else if(target>v[i][m-1])
        {
            continue;
        }
        if (binary_search(v[i].begin(), v[i].end(), target))
        {
            check = true;
        }
        break;
    }
    return check;
} */

//Method3: Imaginary Binary Search
//T.C->O(log(M*N)) & S.C->O(1)
bool solve(vector<vector<int>> &v, int target)
{
    int n = v.size();
    int m = v[0].size();
    bool check = false;

    int low = 0, high = (n * m) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid / m][mid % m] == target)
        {
            check = true;
            break;
        }
        else if (v[mid / m][mid % m] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return check;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v;
    
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j <m; j++)
        {
            int val;
            cin>>val;
            temp.push_back(val);
        }
        v.push_back(temp);
    }
    int target;
    cin>>target;
    bool ans = solve(v,target);
    if(ans)
    {
        cout<<"Element is present!!"<<endl;
    }
    else
    {
        cout<<"Element is not present!!"<<endl;
    }
    return 0;
}