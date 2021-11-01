//Fractional Knapsack
//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;
};

//Method: Pure Greedy
//T.C->O(N*log(N)) & S.C->O(1)
bool comp(Item a, Item b)
{
    double d1 = (double)a.value / (double)a.weight;
    double d2 = (double)b.value / (double)b.weight;
    return d1 > d2;
}

double fractionalKnapsack(int W, vector<Item>arr, int n)
{
    sort(arr.begin(), arr.end(), comp);
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight >= W)
        {
            total += ((double)arr[i].value / (double)arr[i].weight) * W;
            break;
        }
        else
        {
            total += arr[i].value;
            W -= arr[i].weight;
        }
    }
    return total;
}

int main()
{
    int n,W;
    cin>>n>>W;
    vector<Item>v(n);
    for (int i = 0; i <n; i++)
    {
        cin>>v[i].value>>v[i].weight;
    }
    double ans = fractionalKnapsack(W,v,n);
    cout<<ans<<endl;
    return 0;
}