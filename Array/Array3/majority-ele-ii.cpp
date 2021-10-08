//Majority Element-ii
//https://leetcode.com/problems/majority-element-ii/
#include <bits/stdc++.h>
using namespace std;

//Method1: Boyer Moores Voting Algo
//T.C->O(N) & S.C->O(1)
vector<int> majorityElement(vector<int> &arr)
{
    int n = arr.size();
    int c1 = 0, c2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
        {
            c1++;
        }
        else if (arr[i] == ele2)
        {
            c2++;
        }
        else if (c1 == 0)
        {
            ele1 = arr[i];
            c1 = 1;
        }
        else if (c2 == 0)
        {
            ele2 = arr[i];
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    vector<int> v;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
        {
            s1++;
        }
        if (arr[i] == ele2)
        {
            s2++;
        }
    }
    if (s1 > n / 3)
    {
        v.push_back(ele1);
    }
    if (s2 > n / 3)
    {
        v.push_back(ele2);
    }
    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> majorityelements = majorityElement(v);
    cout<<"Majority Elements are: ";
    for(int i=0;i<majorityelements.size();i++)
    {
        cout<<majorityelements[i]<<" ";
    }
    cout<<endl;
    return 0;
}