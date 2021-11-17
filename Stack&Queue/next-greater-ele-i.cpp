// Next Greater Element I
//https://leetcode.com/problems/next-greater-element-i/

#include<bits/stdc++.h>
using namespace std;


//Method: Using Stack + Map
//T.C=>O(N1+N2) && S.C->O(N1)
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    stack<int>st;
    unordered_map<int,int>m;
    vector<int>ans(n1,-1);
    for (int i = 0; i < n2; i++)
    {
        int ele = nums2[i];
        while(!st.empty() && ele>st.top())
        {
            m[st.top()] = ele;
            st.pop();
        }
        st.push(ele);
    }
    for (int i = 0; i <n1; i++)
    {
        if(m.find(nums1[i])!=m.end())
        {
            ans[i]=m[nums1[i]];
        }
    }   
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }
    vector<int>ans = nextGreaterElement(v1,v2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}