//N meetings in one room
//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>p1, pair<int,int>p2)
{
    if(p2.second>p1.second) return true;
    else if(p2.second==p1.second)
    {
        if(p1.first>p1.second) return true;
        else return false;
    }
    return false;
}

//Method: Greedy Approach
//T.C->O(N*log(N)) & S.C->O(N)
int maxMeetings(vector<int>start, vector<int> end, int n)
{
    vector<pair<int,int>>v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].first=start[i];
        v[i].second=end[i];
    }
    sort(v.begin(),v.end(),comp);
    int cnt = 1, endtime = v[0].second; 
    /*for (int i = 0; i < n; i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    } */

    for (int i = 1; i <n; i++)
    {
        if(v[i].first>endtime)
        {
            cnt++;
            endtime = v[i].second;
        }
    }
    return cnt; 
}

int main()
{
    int n;
    cin>>n;
    vector<int>start(n);
    vector<int>end(n);
    for (int i = 0; i < n; i++)
    {
        cin>>start[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>end[i];
    }
    int ans = maxMeetings(start,end,n);
    cout<<ans<<endl;
    return 0;
}