//Best Time to Buy & Sell Stocks
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include<bits/stdc++.h>
using namespace std;

//Method: Using two pointers
//T.C->O(N) & S.C->O(1)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int i = 0, j = 1, maxprofit = 0;
    while (i < n && j < n)
    {
        if (prices[i] > prices[j])
        {
            i = j;
            j++;
        }
        else
        {
            maxprofit = max(maxprofit, prices[j] - prices[i]);
            j++;
        }
    }
    return maxprofit;
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
    int maxprofit = maxProfit(v);
    cout<<"Maxprofit is: "<<maxprofit<<endl;
    return 0;
}