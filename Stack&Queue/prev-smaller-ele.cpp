//Nearest Smaller Element
//https://www.interviewbit.com/problems/nearest-smaller-element/
#include <bits/stdc++.h>
using namespace std;

//Method: Using Monotonus Stack
//T.C=>O(2*N+2*N) && S.C->O(N)
vector<int>prevSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int elem = nums[i];
        while (!s.empty() && nums[s.top()] >= elem)
        {
            s.pop();
        }
        if (!s.empty())
            ans[i] = nums[s.top()];
        s.push(i);
    }
    return ans;
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
    vector<int> ans = prevSmaller(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}