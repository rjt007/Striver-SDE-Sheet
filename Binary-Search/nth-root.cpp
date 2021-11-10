//Nth root of a number
#include<bits/stdc++.h>
using namespace std;


//Method: Using Binary Search
//T.C->O(N*log(M*(10^d))) && S.C->O(1)

double multiply(double mid, int n)
{
    double ans = 1.0;
    for (int i = 0; i < n; i++)
    {
        ans *= mid;
    }
    return ans;
}

double nthroot(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-6;
    while ((high-low)>eps)
    {
        double mid = (low+high)/2.0;
        if(multiply(mid,n)<m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low; // or return high;
}

int main()
{
    int n,m;
    cin>>n>>m;
    double ans = nthroot(n,m);
    cout<<n<<"th root of "<<m<<" is: "<<ans<<endl;
    return 0;
}