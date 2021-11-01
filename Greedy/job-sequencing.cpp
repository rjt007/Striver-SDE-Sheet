//Job Sequencing Problem
//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;    
    int dead;   
    int profit; 
};

//Method: Greedy
//T.C->O(N^2+N*log(N)) && S.C->O(N)
bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(vector<Job>arr, int n)
{
    // your code here
    sort(arr.begin(), arr.end(), comp);
    int maxi = arr[0].dead;
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i].dead);
    }

    int slot[maxi + 1];

    for (int i = 0; i <= maxi; i++)
        slot[i] = -1;

    int countJobs = 0, jobProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    vector<int> ans(2);
    ans[0] = countJobs;
    ans[1] = jobProfit;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<Job>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i].id>>v[i].dead>>v[i].profit;
    }
    vector<int>ans = JobScheduling(v,n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}