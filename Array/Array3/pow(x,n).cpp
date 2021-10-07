//Pow(x,n)
//https://leetcode.com/problems/powx-n/
#include <bits/stdc++.h>
using namespace std;

/* //Method1: Using Recursion
//T.C->O(log(N) && S.C->O(1))
double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    double p = myPow(x, n / 2);
    if (n % 2 == 0)
    {
        return p * p;
    }
    return n > 0 ? x * p * p : (1 / x) * p * p;
} */

//Method2: Using Iteration
//T.C->O(log(N)) && S.C->O(1)
double myPow(double x, int n)
{
    double ans = 1.0;
    long long m = n;
    if(n<0)
    {
        m = -1*m;
    }
    while(m)
    {
        if(m%2==0)
        {
            x = x*x;
            m/=2;
        }
        else
        {
            ans*=x;
            m--;
        }
    }
    return n>0?ans:(double)(1.0)/(double)(ans);
}

int main()
{
    int x,n;
    cin>>x>>n;
    double ans = myPow(x,n);
    cout<<"x raise to the power n is: "<<ans<<endl;
    return 0;
}