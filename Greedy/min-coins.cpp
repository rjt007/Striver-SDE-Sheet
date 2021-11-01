//Minimum Coin Change
//https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
#include <bits/stdc++.h>
using namespace std;

//Method: Greedy
//T.C->O(M*log(M)) && S.C->O(1)
int solve(int V, int M, vector<int>coin)
{
    sort(coin.begin(),coin.end(),greater<int>());
    int i=0,cnt=0;
    while (V>0)
    {
        if(coin[i]<=V)
        {
            V-=coin[i];
            cnt++;
        }
        else
        {
            i++;
        }
    }
    if(V!=0) //handling the case if sum not be possible.
    {
        return -1;
    }
    return cnt;
}

int main()
{
    int V,M;
    cin>>V>>M;
    vector<int>coin(M);
    for (int i = 0; i < M; i++)
    {
        cin>>coin[i];
    }
    int ans = solve(V,M,coin);
    cout<<ans<<endl;
    return 0;
}